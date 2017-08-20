/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 13:39:11 by kromain           #+#    #+#             */
/*   Updated: 2017/05/13 01:34:26 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isprimeaux(int n, int tmp)
{
	if (n < 2 || tmp < 2)
		return (n < 2 ? 0 : 1);
	return (n % tmp == 0 ? 0 : ft_isprimeaux(n, --tmp));
}

int			ft_isprime(int n)
{
	return (ft_isprimeaux(n, ft_sqrt(n)));
}
