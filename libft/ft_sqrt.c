/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:39:11 by kromain           #+#    #+#             */
/*   Updated: 2017/01/13 01:34:26 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sqrtaux(long long n, long long tmp)
{
	if (tmp <= 0)
		return (0);
	return ((tmp * tmp) <= n ? tmp : ft_sqrtaux(n, --tmp));
}

int			ft_sqrt(int n)
{
	return (ft_sqrtaux(n, n));
}
