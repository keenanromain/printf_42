#include "../inc/ft_printf.h"

int		print_percent(t_flag *f, int len)
{
	char *s;

	s = ft_strdup("%");
	handle_s_width(&s, f);
	ft_putstr(s);
	len = ft_strlen(s);
	ft_strdel(&s);
	return (len);
}

int		print_invalid(t_flag *f)
{
	char *s;

	s = ft_strnew(1);
	if (f->minus || f->space || !f->width || !f->new_p)
	{
		s[0] = f->spec;
		handle_s_width(&s, f);
	}
	else
	{
		handle_s_width(&s, f);
		s[ft_strlen(s) - 1] = f->spec;
	}
	ft_putstr(s);
	ft_strdel(&s);
	return (f->width);
}
