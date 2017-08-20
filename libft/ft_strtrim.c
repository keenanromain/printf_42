/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 21:03:24 by kromain           #+#    #+#             */
/*   Updated: 2017/01/19 00:01:17 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			len;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	len = ft_strlen(s) - 1;
	while (len > i && ft_isspace(s[len]))
		len--;
	if (len < i)
		return (ft_strdup(""));
	len += 1;
	return (ft_strsub(s, i, len - (size_t)i));
}
