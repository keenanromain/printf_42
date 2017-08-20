/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:12:48 by kromain           #+#    #+#             */
/*   Updated: 2017/01/12 18:41:31 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = -1;
	while (++i < len)
	{
		if (src[i] != '\0')
			dst[i] = src[i];
		else
		{
			while (i < len)
				dst[i++] = '\0';
		}
	}
	return (dst);
}
