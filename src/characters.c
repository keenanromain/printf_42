#include "../inc/ft_printf.h"

void	wchr_to_c(wchar_t wc, char *s)
{
	if (wc <= 0x7F)
		s[0] = wc;
	else if (wc <= 0x7FF)
	{
		s[0] = 192 | (((unsigned int)(wc) >> 6) & 63);
		s[1] = 128 | ((unsigned int)(wc) & 63);
	}
	else if (wc <= 0xFFFF)
	{
		s[0] = 224 | (((unsigned int)(wc) >> 12) & 63);
		s[1] = 128 | (((unsigned int)(wc) >> 6) & 63);
		s[2] = 128 | ((unsigned int)(wc) & 63);
	}
	else if (wc <= 0x10FFFF)
	{
		s[0] = 240 | (((unsigned int)(wc) >> 18) & 63);
		s[1] = 128 | (((unsigned int)(wc) >> 12) & 63);
		s[2] = 128 | (((unsigned int)(wc) >> 6) & 63);
		s[3] = 128 | ((unsigned int)(wc) & 63);
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
	wchr_to_c(wc, s);
	handle_s_width(&s, f);
	ft_putstr(s);
	return (len);
}

int		print_chr(va_list *args, t_flag *f, int len)
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

/*
int		print_chr(va_list *args, t_flag *f, int len)
{
	char	*s;
	int		flag;
	int		c;

	flag = 0;
	c = va_arg(*args, int);
	s = ft_strnew(1);
	if (f->minus && !c)
		len += write(1, "\0", 1);
	if (c == 0)
		flag = 1;
	else
		s[0] = c;
	f->width -= f->width > 0 ? flag : 0;
	handle_s_width(&s, f);
	len += ft_strlen(s);
	ft_putstr(s);
	if (flag == 1 && !f->minus)
		len += write(1, "\0", 1);
	ft_strdel(&s);
	return (len);
}
*/
