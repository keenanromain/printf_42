/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:15:49 by kromain           #+#    #+#             */
/*   Updated: 2017/01/13 01:30:09 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new_string;

	if (s && f)
	{
		i = 0;
		new_string = malloc(sizeof(char) * ft_strlen(s) + 1);
		if (new_string == NULL)
			return (NULL);
		while (s[i])
		{
			new_string[i] = (*f)(s[i]);
			i++;
		}
		new_string[i] = '\0';
		return (new_string);
	}
	return (NULL);
}
