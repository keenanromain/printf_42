/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:41:04 by kromain           #+#    #+#             */
/*   Updated: 2017/01/13 01:34:44 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			new_string[i] = (*f)(i, s[i]);
			i++;
		}
		new_string[i] = '\0';
		return (new_string);
	}
	return (NULL);
}
