#include "../inc/ft_printf.h"

int			handle_i_width(unsigned int num, t_flag *f)
{
	int len;
	char *s;

	len = 0;
	if (f->width == 0)
		return (len);
	s = ft_strnew(f->width);
	f->width < 0 ? ft_memset(s, ' ', num) : ft_memset(s, ' ', f->width - num);
	ft_putstr(s);
	len = ft_strlen(s);
	ft_strdel(&s);
	return (len);
}

static char	*justification(char **s, t_flag *f, char *tmp)
{
	if (!f->zero)
		ft_memset(tmp, ' ', f->width - ft_strlen(*s));
	else
	{
		if (*s[0] == '-' || f->space)
		{
			ft_memset(tmp, '0', f->width - ft_strlen(*s) + 1);
			tmp[0] = f->space ? ' ' : '-';
			*s = ft_strsub(*s, 1, ft_strlen(*s) - 1);
			tmp = ft_strjoin(tmp, *s);
		}
		else
			ft_memset(tmp, '0', f->width - ft_strlen(*s));
	}
	ft_strcpy(tmp + f->width - ft_strlen(*s), *s);
	return (tmp);
}

void		handle_s_width(char **s, t_flag *f)
{
	char *tmp;

	if (f->new_w == 0 || (unsigned int)f->width <= ft_strlen(*s))
		return ;
	tmp = ft_strnew(f->width);
	if (!f->minus)
	{
		tmp = justification(s, f, tmp);
		*s = tmp;
		return ;
	}
	ft_strcpy(tmp, *s);
	ft_memset(tmp + ft_strlen(*s), ' ', \
			f->width - ft_strlen(*s));
	*s = tmp;
}
