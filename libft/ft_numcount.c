/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:21:01 by kromain           #+#    #+#             */
/*   Updated: 2017/01/13 16:48:08 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numcount(const char *s)
{
	int count;
	int i;

	count = 0;
	i = -1;
	while (s[++i])
		if (ft_isdigit(s[i]) && !ft_isdigit(s[i + 1]))
			count++;
	return (count);
}
