/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:46:50 by kromain           #+#    #+#             */
/*   Updated: 2017/01/21 11:38:13 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *swapper;

	swapper = (void *)malloc(sizeof(char) * len);
	if (swapper)
	{
		ft_memcpy(swapper, src, len);
		ft_memcpy(dst, swapper, len);
		free(swapper);
	}
	return (dst);
}
