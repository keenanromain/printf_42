/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 11:46:50 by kromain           #+#    #+#             */
/*   Updated: 2017/09/07 12:32:12 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		dispatch_unsigned(t_flags *f, va_list *av)
{
	if (f->spec == 'o' || f->spec == 'O')
	{
		f->mod = (f->spec == 'O') ? l : f->mod;
		f->spec = 'o';
		return (print_octal(f, unsigned_type(f, av)));
	}
	else if (f->spec == 'u' || f->spec == 'U')
	{
		f->mod = (f->spec == 'U') ? l : f->mod;
		f->spec = 'u';
		return (print_unsigned(f, unsigned_type(f, av)));
	}
	return (print_hex(f, unsigned_type(f, av)));
}

int				dispatch_number(t_flags *f, va_list *av)
{
	if (f->spec == 'd' || f->spec == 'D' || f->spec == 'i')
	{
		if (f->spec == 'D')
			f->mod = l;
		f->spec = 'd';
		return (print_signed(f, signed_type(f, av)));
	}
	return (dispatch_unsigned(f, av));
}

int				dispatch_non_number(t_flags *f, va_list *av)
{
	if (f->spec == 's' || f->spec == 'S')
		return (f->mod == l || f->spec == 'S' ? \
				print_ws(f, av, 0) : print_s(f, av, 0));
	else if (f->spec == 'c' || f->spec == 'C')
		return (f->mod == l || f->spec == 'C' ? \
				print_wc(f, av, 0) : print_c(f, av, 0));
	else if (f->spec == 'p')
		return (print_pointer(f, av));
	return (print_percent(f, av));
}

int				dispatcher(t_flags *f, va_list *av)
{
	if (ft_strchr("idDxXouUO", f->spec))
		return (dispatch_number(f, av));
	else if (ft_strchr("SscCp%", f->spec))
		return (dispatch_non_number(f, av));
	return (print_invalid(f));
}
