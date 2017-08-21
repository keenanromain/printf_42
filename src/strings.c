#include "../inc/ft_printf.h"

static char		*wchars_to_s(wchar_t *ws)
{
	size_t	len;
	char	*res;
	int		i;

	len = ft_wstrlen(ws);
	res = ft_strnew(len);
	i = 0;
	while (*ws)
	{
		wchar_to_c(*ws, res + i);
		i += ft_wcharlen(*ws);
		ws++;
	}
	return (res);
}

static int		invalid(t_flag *f, int len, char *s)
{
	if (!f->new_p || (f->new_p && f->precision >= 6))
		s = ft_strdup("(null)");
	handle_s_width(&s, f);
	len = ft_strlen(s);
	ft_putstr(s);
	ft_strdel(&s);
	return (len);
}

int		print_wstr(va_list *args, t_flag *f, int len)
{
	char	*s;
	wchar_t	*ws;

	if (!(ws = ft_wstrdup(va_arg(*args, wchar_t*))))
		return (invalid(f, len, (s = ft_strdup(""))));
	handle_ws_prec(&ws, f);
	s = wchars_to_s(ws);
	handle_s_width(&s, f);
	if (f->width)
		len = (unsigned int)f->width > ft_wstrlen(ws) ? \
			  f->width : ft_wstrlen(ws);
	else
		len = ft_wstrlen(ws);
	ft_putstr(s);
	ft_strdel(&s);
	return (len);
}

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
