#include "ft_printf.h"

int		print_str(va_list *args, t_flag *f, int len)
{
	char *s;

	if (!(s = va_arg(*args, char*)))
	{
		if (f->new_p == 0 || (f->new_p && f->precision))
			s = ft_strdup("(null)");
		else
			s = ft_strdup("");
	}
	s = ft_strdup(s);
	len = ft_strlen(s);
	f->len = len;
	handle_s_prec(&s, f);
	handle_s_width(&s, f);
	ft_putstr(s);
	ft_strdel(&s);
	return (len);
}
