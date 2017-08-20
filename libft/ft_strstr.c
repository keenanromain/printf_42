/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:04:42 by kromain           #+#    #+#             */
/*   Updated: 2017/01/13 01:26:04 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int k;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i])
	{
		j = i;
		k = 0;
		while (big[j] == little[k])
		{
			j++;
			k++;
			if (little[k] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
