#include "../inc/ft_printf.h"

int		print_percent(t_flag *f)
{
	char *s;

	s = ft_strdup("%");
	handle_s_width(&s, f);
	ft_putchar('%');
	ft_strdel(&s);
	return (1);
}

//see about else statement below....
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
		s[0] = f->spec;
	}
	ft_putstr(s);
	ft_strdel(&s);
	return (f->width);
}
