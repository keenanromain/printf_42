/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 18:42:22 by kromain           #+#    #+#             */
/*   Updated: 2017/01/13 01:31:38 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *swapper;

	swapper = s1;
	while (*swapper)
		swapper++;
	while (*s2 && n--)
	{
		*swapper = *s2;
		swapper++;
		s2++;
	}
	*swapper = '\0';
	return (s1);
}
