/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:22:58 by kromain           #+#    #+#             */
/*   Updated: 2017/01/13 10:43:21 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bytes;

	if (len == 0)
		return (b);
	bytes = (unsigned char *)b;
	while (len > 0)
	{
		*bytes = (unsigned char)c;
		bytes++;
		len--;
	}
	return (b);
}
