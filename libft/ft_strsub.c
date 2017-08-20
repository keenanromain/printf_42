/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:37:03 by kromain           #+#    #+#             */
/*   Updated: 2017/01/13 16:45:59 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*small;
	size_t	i;

	if (s == NULL)
		return (NULL);
	small = (char *)malloc(sizeof(char) * len + 1);
	if (small == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		small[i] = s[start + i];
		i++;
	}
	small[i] = '\0';
	return (small);
}
