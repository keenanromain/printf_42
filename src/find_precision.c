/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 11:46:50 by kromain           #+#    #+#             */
/*   Updated: 2017/09/07 12:32:12 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	i_precision(char **s, t_flags *f)
{
	char	*tmp;

	if (!f->set_prec || f->len > f->prec)
		return ;
	tmp = ft_strnew(f->prec);
	f->zero = false;
	if (*s[0] == '-')
	{
		ft_memset(tmp, '0', f->prec - (ft_strlen(*s) - 1));
		tmp = ft_strjoin("-", tmp);
		*s = ft_strsub(*s, 1, ft_strlen(*s) - 1);
		tmp = ft_strjoin(tmp, *s);
		ft_strdel(s);
		*s = tmp;
		return ;
	}
	ft_memset(tmp, '0', f->prec - f->len);
	ft_strcpy(tmp + f->prec - ft_strlen(*s), *s);
	ft_strdel(s);
	*s = tmp;
}

void	s_precision(char **s, t_flags *f)
{
	if (!f->set_prec || f->len <= f->prec)
		return ;
	*s = ft_strndup(*s, f->prec);
}

void	ws_precision(wchar_t **ws, t_flags *f)
{
	size_t	len;

	if (!f->set_prec || ft_wstrlen(*ws) <= f->prec)
		return ;
	len = 0;
	while (**ws && len <= f->prec)
	{
		len += ft_wcharlen(**ws);
		ws++;
	}
	*(*ws - 1) = 0;
}
