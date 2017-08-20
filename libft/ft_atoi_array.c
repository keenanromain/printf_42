/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:21:01 by kromain           #+#    #+#             */
/*   Updated: 2017/05/11 16:48:08 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_atoi_array(const char *s)
{
	int *ret;
	int i;

	ret = (int *)ft_memalloc((ft_numcount(s) * sizeof(int)) + 1);
	i = 0;
	while (*s)
	{
		if (*s == '-' || ft_isdigit(*s))
			ret[++i] = ft_atoi(s);
		s = ((ft_strclen(s, ' ')) ? s + ft_strclen(s, ' ') : s + 1);
	}
	ret[0] = i;
	return (ret);
}
