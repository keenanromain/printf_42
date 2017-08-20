#include "ft_printf.h"

static int invalid(t_flag *f, char **p)
{
	handle_i_prec(p, f);
	if (f->zero && (f->width -= 2))
		handle_s_width(p, f);
	if (f->precision == 0 && f->new_p)
		*p = ft_strdup("");
	*p = ft_strjoin("0x", *p);
	if (!f->zero)
		handle_s_width(p, f);
	return (ft_strlen(*p));
}

static int valid(t_flag *f, char **p)
{
	handle_i_prec(p, f);
	if (f->hash && f->new_p)
		f->zero = false;
	*p = ft_strjoin("0x", *p);
	handle_s_width(p, f);
	return (ft_strlen(*p));
}

int		print_ptr(va_list *args, t_flag *f, int len)
{
	char *p;

	p = va_arg(*args, void*);
	p = ft_itoa_unsigned((unsigned long long)p, 16);
	f->len = ft_strlen(p);
	len = ft_strcmp(p, "0") ? valid(f, &p) : invalid(f, &p);
	ft_putstr(ft_downcase(p));
	ft_strdel(&p);
	return (len);
}
