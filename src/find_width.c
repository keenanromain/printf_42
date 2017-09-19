/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:06:09 by kromain           #+#    #+#             */
/*   Updated: 2017/02/01 11:04:09 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			i_width(unsigned int i, t_flags *f)
{
	int		len;
	char	*s;

	len = 0;
	if (!f->set_width)
		return (len);
	s = ft_strnew(f->width);
	f->width < 0 ? ft_memset(s, ' ', i) : ft_memset(s, ' ', f->width - i);
	len = ft_strlen(s);
	ft_putstr(s);
	ft_strdel(&s);
	return (len);
}

static char	*justification(char **s, t_flags *f, char *tmp)
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

void		s_width(char **s, t_flags *f)
{
	char	*tmp;

	if (!f->set_width || (unsigned int)f->width <= ft_strlen(*s))
		return ;
	tmp = ft_strnew(f->width);
	if (!f->minus)
		tmp = justification(s, f, tmp);
	else
	{
		ft_strcpy(tmp, *s);
		ft_memset(tmp + ft_strlen(*s), ' ', f->width - ft_strlen(*s));
	}
	ft_strdel(s);
	*s = ft_strdup(tmp);
	ft_strdel(&tmp);
}
