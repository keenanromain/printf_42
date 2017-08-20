/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:10:25 by kromain           #+#    #+#             */
/*   Updated: 2017/01/12 21:57:56 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *fresh_string;

	fresh_string = (char *)malloc(sizeof(char) * size + 1);
	if (fresh_string == NULL)
		return (NULL);
	else
	{
		ft_memset(fresh_string, '\0', size + 1);
		return (fresh_string);
	}
}
