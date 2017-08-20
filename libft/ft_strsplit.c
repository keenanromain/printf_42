/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:59:15 by kromain           #+#    #+#             */
/*   Updated: 2017/01/21 11:54:44 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nullterms(const char *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		words;
	int		i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = 0;
	words = ft_nullterms((const char *)s, c);
	if (!(array = (char **)malloc(sizeof(*array) * (words + 1))))
		return (NULL);
	while (words--)
	{
		while (*s && *s == c)
			s++;
		len = ft_strclen((const char *)s, c);
		if (!(array[i++] = ft_strsub((const char *)s, 0, len)))
			return (NULL);
		s += len;
	}
	array[i] = NULL;
	return (array);
}
