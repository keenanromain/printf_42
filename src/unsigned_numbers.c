#include "../inc/ft_printf.h"

unsigned long long		get_unsigned(va_list *args, t_flag *f)
{
	if (f->mod == h)
		return (unsigned long long)(unsigned short)va_arg(*args, unsigned int);
	else if (f->mod == hh)
		return (unsigned long long)(unsigned int)va_arg(*args, unsigned int);
	else if (f->mod == l)
		return (unsigned long long)va_arg(*args, unsigned long);
	else if (f->mod == ll)
		return (unsigned long long)va_arg(*args, unsigned long long);
	else if (f->mod == no)
		return (unsigned long long)va_arg(*args, unsigned int);
	else if (f->mod == j)
		return (unsigned long long)va_arg(*args, uintmax_t);
	else if (f->mod == z)
		return (unsigned long long)va_arg(*args, size_t);
	else if (f->mod == t)
		return (unsigned long long)va_arg(*args, unsigned long long);
	return (0);
}

static int				valid(t_flag *f, char *s)
{
	f->len = ft_strlen(s);
	handle_i_prec(&s, f);
	if (f->zero && f->hash)
	{
		f->width -= 2;
		handle_s_width(&s, f);
	}
	if (f->hash && ft_strcmp("0", s))
		s = ft_strjoin("0X", s);
	handle_s_width(&s, f);
	!(f->spec == 'X') ? ft_putstr(ft_downcase(s)) : ft_putstr(s);
	return (ft_strlen(s));
}

int						print_hex(t_flag *f, unsigned long long type)
{
	char	*s;
	int		len;

	if (type)
		return (valid(f, (ft_itoa_unsigned(type, 16))));
	s = ft_strnew(1);
	if (f->new_p && f->precision == 0)
		s[0] = 0;
	else
		s = ft_strjoin("0", s);
	handle_i_prec(&s, f);
	handle_s_width(&s, f);
	len = ft_strlen(s);
	ft_putstr(s);
	ft_strdel(&s);
	return (len);
}

int						print_octal(t_flag *f, unsigned long long type)
{
	char	*s;
	int		len;

	if (f->hash)
	{
		s = ft_strjoin("0", ft_itoa_unsigned(type, 8));
		if (!type && (!f->new_p || (f->new_p && !f->precision)))
			return (write(1, "0", 1));
	}
	else
		if (!type && !f->precision)
			return (handle_i_width(0, f));
	f->len = ft_strlen(s);
	handle_i_prec(&s, f);
	handle_s_width(&s, f);
	len = ft_strlen(s);
	ft_putstr(s);
	ft_strdel(&s);
	return (len);
}

int						print_uint(t_flag *f, unsigned long long type)
{
	char	*s;
	int		len;

	if (f->precision == 0 && type == 0)
		return (0);
	s = ft_itoa_unsigned(type, 10);
	f->len = ft_strlen(s);
	handle_i_prec(&s, f);
	handle_s_width(&s, f);
	len = ft_strlen(s);
	ft_putstr(s);
	ft_strdel(&s);
	return (len);
}
