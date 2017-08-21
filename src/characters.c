#include "../inc/ft_printf.h"

void			wchar_to_c(wchar_t wchar, char *s)
{
	if (wchar <= 0x7F)
		s[0] = wchar;
	else if (wchar <= 0x7FF)
	{
		s[0] = 192 | (((unsigned int)(wchar) >> 6) & 63);
		s[1] = 128 | ((unsigned int)(wchar) & 63);
	}
	else if (wchar <= 0xFFFF)
	{
		s[0] = 224 | (((unsigned int)(wchar) >> 12) & 63);
		s[1] = 128 | (((unsigned int)(wchar) >> 6) & 63);
		s[2] = 128 | ((unsigned int)(wchar) & 63);
	}
	else if (wchar <= 0x10FFFF)
	{
		s[0] = 240 | (((unsigned int)(wchar) >> 18) & 63);
		s[1] = 128 | (((unsigned int)(wchar) >> 12) & 63);
		s[2] = 128 | (((unsigned int)(wchar) >> 6) & 63);
		s[3] = 128 | ((unsigned int)(wchar) & 63);
	}
}

int		print_wchr(va_list *args, t_flag *f, int len)
{
	char *s;
	wchar_t wc;

	wc = va_arg(*args, wchar_t);
	s = ft_strnew(ft_wcharlen(wc));
	len = ft_strlen(s);
	if (wc == 0)
		ft_putchar('\0');
	wchar_to_c(wc, s);
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
