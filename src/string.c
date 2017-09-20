/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 17:28:33 by kromain           #+#    #+#             */
/*   Updated: 2017/09/05 12:38:24 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		null(t_flags *f, int len, char *s)
{
	if (!f->set_prec || (f->set_prec && f->prec >= 6))
		s = ft_strdup("(null)");
	else
		s = ft_strdup("");
	s_width(&s, f);
	ft_putstr(s);
	len = ft_strlen(s);
	ft_strdel(&s);
	return (len);
}

int				print_ws(t_flags *f, va_list *av, int len)
{
	wchar_t	*ws;
	char	*s;

	if (!(ws = ft_wstrdup(va_arg(*av, wchar_t*))))
		return (null(f, len, NULL));
	ws_precision(&ws, f);
	s = ws_to_s(ws, ft_wstrlen(ws), 0);
	s_width(&s, f);
	if (f->set_width)
		len = ((unsigned int)f->width > ft_wstrlen(ws)) ? \
			f->width : ft_wstrlen(ws);
	else
		len = ft_wstrlen(ws);
	ft_putstr(s);
	ft_strdel(&s);
	free(ws);
	ws = NULL;
	return (len);
}

static int		helper(char **s, t_flags *f, int len)
{
	f->len = ft_strlen(*s);
	s_precision(s, f);
	s_width(s, f);
	len = ft_strlen(*s);
	ft_putstr(*s);
	ft_strdel(s);
	return (len);
}

int				print_s(t_flags *f, va_list *av, int len)
{
	char	*s;
	char	*tmp;
	char	*arg;

	s = NULL;
	tmp = NULL;
	if (!(arg = va_arg(*av, char*)))
	{
		if (!f->set_prec || (f->set_prec && f->prec))
			s = ft_strdup("(null)");
		else
			s = ft_strdup("");
	}
	if (s)
	{
		tmp = ft_strdup(s);
		ft_strdel(&s);
	}
	s = ft_strdup(tmp ? tmp : arg);
	if (tmp)
		ft_strdel(&tmp);
	return (helper(&s, f, len));
}
