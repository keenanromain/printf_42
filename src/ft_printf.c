/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:25:23 by kromain           #+#    #+#             */
/*   Updated: 2017/09/08 17:10:18 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		determine_fmt(char *fmt, va_list *av, int *size)
{
	char		*s;
	char		*tmp;
	int			i;

	s = NULL;
	tmp = fmt;
	i = -1;
	while (tmp[++i])
	{
		if (ft_strchr(SPEC, tmp[i]) || (ft_isalpha(tmp[i]) \
		&& !ft_strchr(POSS, tmp[i])))
		{
			s = ft_strndup(fmt, ++i);
			break ;
		}
	}
	if (!s)
		return (0);
	*size += determine_flags(s, av);
	ft_strdel(&s);
	return (i);
}

static int		run_thru_string(char *fmt, va_list *av, int *size)
{
	int			*p;

	p = 0;
	while (*fmt)
	{
		if (*fmt && *fmt != '%')
			*size += write(1, fmt++, 1);
		else
		{
			if (fmt++ && *fmt == 'n')
			{
				p = va_arg(*av, int*);
				*p = *size;
				fmt++;
			}
			else
				fmt += determine_fmt(fmt, av, size);
		}
	}
	return (*size);
}

int				ft_printf(const char *format, ...)
{
	va_list		av;
	int			size;

	size = 0;
	if (!format)
		return (size);
	va_start(av, format);
	size = run_thru_string((char *)format, &av, &size);
	va_end(av);
	return (size);
}
