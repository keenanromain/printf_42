/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:10:10 by kromain           #+#    #+#             */
/*   Updated: 2017/01/19 21:37:27 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_whatsign(int *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	return (0);
}

char			*ft_itoa(int n)
{
	int		temp;
	int		positions;
	int		sign;
	char	*string;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	temp = n;
	positions = 2;
	sign = ft_whatsign(&n);
	while (temp /= 10)
		positions++;
	positions += sign;
	if (!(string = (char *)malloc(sizeof(char) * positions)))
		return (NULL);
	string[--positions] = '\0';
	while (positions--)
	{
		string[positions] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == 1)
		string[0] = '-';
	return (string);
}
