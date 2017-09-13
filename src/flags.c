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

static void		determine_width(char *s, t_flags *f, int i)
{
	f->width = 1;
	f->prec = 1;
	while (s[++i])
	{
		if (s[i] != '.' && s[i] != '0' && ft_isdigit(s[i]))
		{
			f->set_width = true;
			f->width = ft_atoi(s + i);
			while (s[i] && ft_isdigit(s[i]))
				++i;
		}
		if (s[i] == '.' && s[i + 1] != '*')
		{
			f->set_prec = true;
			f->prec = ft_atoi(s + i + 1);
			while (s[i] && ft_isdigit(s[i + 1]))
				++i;
		}
	}
}

static void		determine_asterik(char *s, t_flags *f, va_list *av, int i)
{
	int num;

	while (s[++i])
	{
		if (s[i] == '*' && !ft_isdigit(s[i + 1]))
		{
			num = va_arg(*av, int);
			if (s[i - 1] == '.')
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
		else if (s[i] == '*')
			num = va_arg(*av, int);
	}
}

static void		determine_mod(char *s, t_flags *f, int i)
{
	while (s[++i])
	{
		if (s[i] == 'h')
			f->mod = (s[++i] == 'h') ? hh : h;
		else if (s[i] == 'l')
			f->mod = (s[++i] == 'l') ? ll : l;
		else if (s[i] == 'j')
			f->mod = j;
		else if (s[i] == 'z')
			f->mod = z;
		else if (s[i] == 't')
			f->mod = t;
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
	determine_width(s, f, -1);
	determine_asterik(s, f, av, -1);
	determine_mod(s, f, -1);
	i = dispatcher(f, av);
	free(f);
	return (i);
}
