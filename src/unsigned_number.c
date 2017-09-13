/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 06:08:41 by kromain           #+#    #+#             */
/*   Updated: 2017/09/11 15:25:32 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	unsigned_type(t_flags *f, va_list *av)
{
	if (f->mod == h)
		return (unsigned long long)(unsigned short)va_arg(*av, unsigned int);
	else if (f->mod == hh)
		return (unsigned long long)(unsigned char)va_arg(*av, unsigned int);
	else if (f->mod == l)
		return (unsigned long long)va_arg(*av, unsigned long);
	else if (f->mod == ll)
		return (unsigned long long)va_arg(*av, unsigned long long);
	else if (f->mod == j)
		return (unsigned long long)va_arg(*av, uintmax_t);
	else if (f->mod == z)
		return (unsigned long long)va_arg(*av, size_t);
	else if (f->mod == t)
		return (unsigned long long)va_arg(*av, unsigned long long);
	return (unsigned long long)va_arg(*av, unsigned int);
}

int					print_octal(t_flags *f, unsigned long long type)
{
	char				*s;

	s = ft_itoa_u(type, 8);
	if (f->pound)
	{
		s = ft_strjoin("0", s);
		if (!type && (!f->set_prec || (f->set_prec && !f->prec)))
			return (write(1, "0", 1));
	}
	else
	{
		if (!type && !f->prec)
			return (i_width(0, f));
	}
	f->len = ft_strlen(s);
	i_precision(&s, f);
	s_width(&s, f);
	ft_putstr(s);
	return (ft_strlen(s));
}

int					print_unsigned(t_flags *f, unsigned long long type)
{
	char				*s;
	int					len;

	s = ft_itoa_u(type, 10);
	if (!f->prec && !type)
		return (0);
	f->len = ft_strlen(s);
	i_precision(&s, f);
	s_width(&s, f);
	ft_putstr(s);
	len = ft_strlen(s);
	ft_strdel(&s);
	return (len);
}

static int			valid(t_flags *f, char *s)
{
	f->len = ft_strlen(s);
	i_precision(&s, f);
	if (f->zero && f->pound)
	{
		f->width -= 2;
		s_width(&s, f);
	}
	if (ft_strcmp("0", s) && f->pound)
		s = ft_strjoin("0X", s);
	s_width(&s, f);
	!(f->spec == 'X') ? ft_putdowncase(s) : ft_putstr(s);
	return (ft_strlen(s));
}

int					print_hex(t_flags *f, unsigned long long type)
{
	char				*s;
	int					len;

	if (type)
		return (valid(f, ft_itoa_u(type, 16)));
	s = ft_strnew(1);
	if (f->set_prec && !f->prec)
		s[0] = 0;
	else
		s = ft_strjoin("0", s);
	i_precision(&s, f);
	s_width(&s, f);
	ft_putstr(s);
	len = ft_strlen(s);
	ft_strdel(&s);
	return (len);
}
