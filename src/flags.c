/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 17:28:25 by kromain           #+#    #+#             */
/*   Updated: 2017/08/21 17:28:26 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		determine_width(char *s, t_flags *f)
{
	f->width = 1;
	f->prec = 1;
	while (*s)
	{
		if (*s != '.' && *s != '0' && ft_isdigit(*s))
		{
			f->set_width = true;
			f->width = ft_atoi(s);
			while (*s && ft_isdigit(*s))
				s++;
		}
		if (*s == '.' && *(s + 1) != '*')
		{
			f->set_prec = true;
			f->prec = ft_atoi(s + 1);
			while (*s && ft_isdigit(*(s + 1)))
				s++;
		}
		s++;
	}
}

static void		determine_asterik(char *s, t_flags *f, va_list *av)
{
	int num;

	while (*s)
	{
		if (*s == '*' && !ft_isdigit(*(s + 1)))
		{
			num = va_arg(*av, int);
			if (*(s - 1) == '.')
			{
				f->set_prec = (num >= 0) ? true : false;
				f->prec = (num >= 0) ? num : 0;
			}
			else
			{
				f->minus = (num < 0) ? true : false;
				f->set_width = true;
				f->width = ft_abs(num);
			}
		}
		else if (*s == '*')
			num = va_arg(*av, int);
		s++;
	}
}

static void		determine_mod(char *s, t_flags *f)
{
	while (*s)
	{
		if (*s == 'h')
			f->mod = (*(s + 1) == 'h' && s++) ? hh : h;
		else if (*s == 'l')
			f->mod = (*(s + 1) == 'l' && s++) ? ll : l;
		else if (*s == 'j')
			f->mod = j;
		else if (*s == 'z')
			f->mod = z;
		else if (*s == 't')
			f->mod = t;
		s++;
	}
}

int				determine_flags(char *s, va_list *av)
{
	int			i;
	t_flags		*f;

	i = -1;
	f = (t_flags *)ft_memalloc(sizeof(t_flags));
	f->spec = s[ft_strlen(s) - 1];
	while (s[++i])
	{
		if (s[i] == '0' && s[i - 1] != '.' && !ft_isdigit(s[i - 1]))
			f->zero = true;
		f->pound = (s[i] == '#') ? true : f->pound;
		f->plus = (s[i] == '+') ? true : f->plus;
		f->minus = (s[i] == '-') ? true : f->minus;
		f->space = (s[i] == ' ') ? true : f->space;
	}
	determine_width(s, f);
	determine_asterik(s, f, av);
	determine_mod(s, f);
	i = dispatcher(f, av);
	free(f);
	f = NULL;
	return (i);
}
