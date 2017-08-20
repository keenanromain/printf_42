/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:48:14 by kromain           #+#    #+#             */
/*   Updated: 2017/01/12 20:05:35 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *catch;

	catch = (char *)s;
	while (*catch != c)
	{
		if (*catch == '\0')
			return (NULL);
		catch++;
	}
	return (catch);
}
