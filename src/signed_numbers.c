#include "../inc/ft_printf.h"

intmax_t	get_signed(va_list *args, t_flag *f)
{
	if (f->mod == h)
		return (intmax_t)(signed int)va_arg(*args, int);
	else if (f->mod == hh)
		return (intmax_t)(short)va_arg(*args, int);
	else if (f->mod == l)
		return (intmax_t)va_arg(*args, long);
	else if (f->mod == ll)
		return (intmax_t)va_arg(*args, long long);
	else if (f->mod == no)
		return (intmax_t)va_arg(*args, int);
	else if (f->mod == j)
		return (intmax_t)va_arg(*args, intmax_t);
	else if (f->mod == z)
		return (intmax_t)va_arg(*args, ssize_t);
	else if (f->mod == t)
		return (intmax_t)va_arg(*args, ptrdiff_t);
	else
		return (0);
}

int			print_int(t_flag *f, intmax_t type)
{
	char *s;

	if (f->precision == 0 && !type)
		return (handle_i_width(0, f));
	s = ft_itoa(type);
	f->len = ft_strlen(s);
	if (f->zero && !f->new_p && !f->minus && f->len < (unsigned int)f->width)
	{
		f->new_p = 1;
		f->precision = (f->plus || type < 0 || f->space) ? f->width -1 : f->width;
	}
	handle_i_prec(&s, f);
	if (f->space && s[0] != '-' && !f->plus)
		s = ft_strjoin(" ", s);
	if (f->plus && type > -1)
		s = ft_strjoin("+", s);
	handle_s_width(&s, f);
	ft_putstr(s);
	return (f->len);
}
