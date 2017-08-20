/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 23:29:49 by kromain           #+#    #+#             */
/*   Updated: 2017/01/18 21:45:37 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char *s2;

	s2 = ft_strnew(n);
	if (s2 == NULL)
		return (NULL);
	ft_strncpy(s2, s1, n);
	return (s2);
}
