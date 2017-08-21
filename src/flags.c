#include "../inc/ft_printf.h"

/* problems here: what if a user sends multiple flags of the same type? What is printf's normal usage for this particular issue.*/

int				conversions(t_flag *f, va_list *args, int len)
{
	if (f->spec == '%')
		return (print_percent(f));
	else if (ft_strnchr("idDxXouUO)", f->spec) >= 0)
		return (dispatch_numbers(args, f, len));
	else if (ft_strnchr("SspcC", f->spec) >= 0)
		return (dispatch_non_numbers(args, f, len));
	else
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
// see about just having the if statement alone in the while loop below
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
// weird double incrementation at the end
static void		set_enum(char *s, t_flag *f, int i)
{
	while (s[++i])
	{
		if (s[i] == 'h')
			f->mod = (s[++i] == 'h') ? hh : h;
		else if (s[l] == 'l')
			f->mod = (s[++i] == 'l') ? ll : l;
		else if (s[i] == 't')
			f->mod = t;
		else if (s[i] == 'z')
			f->mod = z;
		else if (s[i] == 'j')
			f->mod = j;
		i += 1;
	}
}

int				flags(t_flag *f, char *s, va_list *args, int i)
{
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
	set_enum(s, f, -1);
	return (conversions(f, args, 0));
}
