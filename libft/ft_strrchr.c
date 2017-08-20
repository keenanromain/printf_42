/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:22:26 by kromain           #+#    #+#             */
/*   Updated: 2017/01/20 18:05:25 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *catch;

	catch = (char *)s;
	if (!(ft_strchr(s, c)))
		return (NULL);
	while (*catch != '\0')
		catch++;
	while (*catch != c)
		catch--;
	return (catch);
}
