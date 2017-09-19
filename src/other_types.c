/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 17:28:46 by kromain           #+#    #+#             */
/*   Updated: 2017/09/05 09:18:25 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_percent(t_flags *f, va_list *av)
{
	char	*s;
	int		len;

	len = 0;
	(void)av;
	s = ft_strdup("%");
	s_width(&s, f);
	len = ft_strlen(s);
	ft_putstr(s);
	ft_strdel(&s);
	return (len);
}

int			print_invalid(t_flags *f)
{
	char	*s;

	s = ft_strnew(1);
	if (f->minus || f->space || !f->set_width || !f->set_prec)
	{
		s[0] = f->spec;
		s_width(&s, f);
	}
	else
	{
		s_width(&s, f);
		s[ft_strlen(s) - 1] = f->spec;
	}
	ft_putstr(s);
	ft_strdel(&s);
	return (f->width);
}

static int	null(t_flags *f, char **p)
{
	i_precision(p, f);
	if (f->zero)
	{
		f->width -= 2;
		s_width(p, f);
	}
	if (!f->prec && f->set_prec)
		*p = ft_strdup("");
	*p = ft_strjoin("0x", *p);
	if (!f->zero)
		s_width(p, f);
	return (ft_strlen(*p));
}

static int	valid(t_flags *f, char **p)
{
	char *tmp;

	i_precision(p, f);
	if (f->pound && f->set_prec)
		f->zero = 0;
	tmp = ft_strjoin("0x", *p);
	ft_strdel(p);
	*p = ft_strdup(tmp);
	ft_strdel(&tmp);
	s_width(p, f);
	return (ft_strlen(*p));
}

int			print_pointer(t_flags *f, va_list *av)
{
	char	*p;
	int		len;

	len = 0;
	p = va_arg(*av, void*);
	p = ft_itoa_u((unsigned long long)p, 16);
	f->len = ft_strlen(p);
	len = ft_strcmp(p, "0") ? valid(f, &p) : null(f, &p);
	ft_putdowncase(p);
	ft_strdel(&p);
	return (len);
}
