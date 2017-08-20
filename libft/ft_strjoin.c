/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:25:52 by kromain           #+#    #+#             */
/*   Updated: 2016/12/05 13:25:53 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;

	if (!s1 || !s2)
		return (0);
	if ((tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		ft_strcat(ft_strcpy(tmp, (char *)s1), s2);
	return (tmp);
}
