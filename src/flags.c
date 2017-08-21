#include "../inc/ft_printf.h"

int				conversions(t_flag *f, va_list *args, int *len)
{
	if (f->spec == 'n' && (len = va_arg(*args, int*)))
		return ((*len = f->amount));
	if (f->spec == '%')
		return (print_percent(f, *len));
	else if (ft_strnchr("idDxXouUO)", f->spec) >= 0)
		return (dispatch_numbers(args, f));
	else if (ft_strnchr("SspcC", f->spec) >= 0)
		return (dispatch_non_numbers(args, f));
	return (print_invalid(f));
}

static void		set_width(char *s, t_flag *f, int i)
{
	f->width = 1;
	f->precision = 1;
	while (s[++i])
	{
		if (s[i] != '0' && s[i] != '.' && ft_isdigit(s[i]))
		{
			f->new_w = 1;
			f->width = ft_atoi(s + i);
			while (s[i] && ft_isdigit(s[i]))
				++i;
		}
		if (s[i] == '.' && s[i + 1] != '*')
		{
			f->new_p = 1;
			f->precision = ft_atoi(s + i + 1);
			while (s[i] && ft_isdigit(s[i + 1]))
				++i;
		}
	}
}

static void		set_asterik(char *s, t_flag *f, va_list *args, int i)
{
	int num;

	while (s[++i])
	{
		if (s[i] == '*' && !ft_isdigit(s[i + 1]))
		{
			num = va_arg(*args, int);
			if (s[i - 1] == '.')
			{
				f->new_p = (num >= 0) ? 1 : 0;
				f->precision = (num >= 0) ? num : 0;
			}
			else
			{
				f->minus = (num < 0) ? true : false;
				f->new_w = 1;
				f->width = ft_abs(num);
			}
		}
		else if (s[i] == '*')
			num = va_arg(*args, int);
	}
}

static void		set_modifier(char *tmp, t_flag *f)
{
	if (tmp[0] == 'h')
		f->mod = (tmp[1] == 'h') ? hh : h;
	else if (tmp[0] == 'l')
		f->mod = (tmp[1] == 'l') ? ll : l;
	else if (tmp[0] == 't')
		f->mod = t;
	else if (tmp[0] == 'z')
		f->mod = z;
	else if (tmp[0] == 'j')
		f->mod = j;
}

int				flags(t_flag *f, char *s, va_list *args, int i)
{
	char *tmp;

	f->spec = s[ft_strlen(s) - 1];
	while (s[++i])
	{
		f->hash = (s[i] == '#') ? true : f->hash;
		f->plus = (s[i] == '+') ? true : f->plus;
		f->minus = (s[i] == '-') ? true : f->minus;
		f->space = (s[i] == ' ') ? true : f->space;
		if (s[i] == '0' && !ft_isdigit(s[i - 1]) && s[i - 1] != '.')
			f->zero = true;
	}
	set_width(s, f, -1);
	set_asterik(s, f, args, -1);
	tmp = ft_strdup(s);
	while (*tmp)
	{
		set_modifier(tmp, f);
		tmp++;
	}
	ft_strdel(&tmp);
	return (conversions(f, args, 0));
}
