/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 18:50:39 by kromain           #+#    #+#             */
/*   Updated: 2017/01/13 01:11:19 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t connecting_spot;

	i = 0;
	if (size == 0)
		return (ft_strlen(dst));
	while (dst[i] && i < size)
		i++;
	connecting_spot = i;
	while (src[i - connecting_spot] != '\0' && i < (size - 1))
	{
		dst[i] = src[i - connecting_spot];
		i++;
	}
	if (connecting_spot < size)
		dst[i] = '\0';
	return (connecting_spot + ft_strlen(src));
}
