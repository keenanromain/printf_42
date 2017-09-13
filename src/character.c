/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 17:28:33 by kromain           #+#    #+#             */
/*   Updated: 2017/09/05 12:38:24 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_wc(t_flags *f, va_list *av, int len)
{
	char	*s;
	wchar_t	wc;

	wc = va_arg(*av, wchar_t);
	len = ft_wcharlen(wc);
	s = ft_strnew(len);
	if (wc == 0)
		write(1, "\0", 1);
	wc_to_s(wc, s);
	s_width(&s, f);
	ft_putstr(s);
	ft_strdel(&s);
	return (len);
}

int		print_c(t_flags *f, va_list *av, int len)
{
	char	*s;
	int		flag;
	int		num;

	flag = 0;
	num = va_arg(*av, int);
	s = ft_strnew(1);
	if (f->minus && !num)
		len += write(1, "\0", 1);
	if (num == 0)
		flag = 1;
	else
		s[0] = num;
	f->width -= f->width > 0 ? flag : 0;
	s_width(&s, f);
	len += ft_strlen(s);
	ft_putstr(s);
	if (flag && !f->minus)
		len += write(1, "\0", 1);
	ft_strdel(&s);
	return (len);
}
