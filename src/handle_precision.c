#include "../inc/ft_printf.h"

void	handle_s_prec(char **s, t_flag *f)
{
	if (f->new_p == 0 || f->len <= f->precision)
		return ;
	*s = ft_strndup(*s, f->precision);
}

void	handle_i_prec(char **s, t_flag *f)
{
	char *tmp;

	if (f->new_p == 0 || f->len > f->precision)
		return ;
	tmp = ft_strnew(f->precision);
	f->zero = 0;
	if (*s[0] == '-')
	{
		ft_memset(tmp, '0', f->precision - (ft_strlen(*s) - 1));
		tmp = ft_strjoin("-", tmp);
		*s = ft_strsub(*s, 1, ft_strlen(*s) - 1);
		tmp = ft_strjoin(tmp, *s);
		ft_strdel(s);
		*s = tmp;
		return ;
	}
	ft_memset(tmp, '0', f->precision - f->len);
	ft_strcpy(tmp + f->precision - ft_strlen(*s), *s);
	ft_strdel(s);
	*s = tmp;
}

void	handle_ws_prec(wchar_t **ws, t_flag *f)
{
	size_t len;
	size_t i;

	i = -1;
	len = 0;
	if (f->new_p == 0 || ft_wstrlen(*ws) <= f->precision)
		return ;
	while ((*ws)[++i] && len <= f->precision)
		len += ft_wcharlen((*ws)[i]);
	(*ws)[i - 1] = 0;
}
