/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:01:19 by kromain           #+#    #+#             */
/*   Updated: 2017/01/20 20:07:47 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoin(char const *s, char c)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (!s || !c)
		return (NULL);
	len = ft_strlen(s);
	if (!(str = ft_strnew(len + 1)))
		return (NULL);
	i = -1;
	while (++i < len)
		*(str + i) = *(s + i);
	*(str + i) = c;
	return (str);
}
