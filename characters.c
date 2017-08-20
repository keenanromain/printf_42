#include "ft_printf.h"

int		print_wchr(va_list *args, t_flag *f, int len)
{
	char *s;
	wchar_t wc;

	wc = va_arg(*args, wchar_t);
	s = ft_strnew(ft_wcharlen(wc));
	len = ft_strlen(s);
	if (wc == 0)
		ft_putchar('\0');
	wchar_to_s(wc, s);
	handle_s_width(&s, f);
	ft_putstr(s);
	return (len);
}

int				print_chr(va_list *args, t_flag *f, int len)
{
	int i;
	char c;
	char d;

	c = va_arg(*args, int);
	d = (f->zero && !f->minus ? '0' : ' ');
	if (f->minus)
		len += write(1, &c, 1);
	i = (f->width ? -1 : 0);
	if (f->width)
		while (++i < f->width -1)
			len += write(1, &d, 1);
	if (!f->minus)
		len += write(1, &c, 1);
	return (len);
}
