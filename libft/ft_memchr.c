/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:41:34 by kromain           #+#    #+#             */
/*   Updated: 2017/01/13 01:27:54 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*new;

	i = 0;
	new = (unsigned char *)s;
	while (n--)
	{
		if (new[i] == (unsigned char)c)
			return ((void *)new + i);
		i++;
	}
	return (NULL);
}
