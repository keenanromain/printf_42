/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libwc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:28:09 by kromain           #+#    #+#             */
/*   Updated: 2017/09/09 17:28:09 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		wc_to_s(wchar_t wc, char *s)
{
	if ((int)wc <= ONE_BYTE)
		s[0] = wc;
	else if ((int)wc <= TWO_BYTE)
	{
		s[0] = 192 | (((int)(wc) >> 6) & 63);
		s[1] = 128 | ((int)(wc) & 63);
	}
	else if ((int)wc <= THREE_BYTE)
	{
		s[0] = 224 | (((int)(wc) >> 12) & 63);
		s[1] = 128 | (((int)(wc) >> 6) & 63);
		s[2] = 128 | ((int)(wc) & 63);
	}
	else if ((int)wc <= FOUR_BYTE)
	{
		s[0] = 240 | (((int)(wc) >> 18) & 63);
		s[1] = 128 | (((int)(wc) >> 12) & 63);
		s[2] = 128 | (((int)(wc) >> 6) & 63);
		s[3] = 128 | ((int)(wc) & 63);
	}
}

char		*ws_to_s(wchar_t *ws, size_t len, int i)
{
	char	*res;

	res = ft_strnew(len);
	while (*ws)
	{
		wc_to_s(*ws, res + i);
		i += ft_wcharlen(*ws);
		ws++;
	}
	return (res);
}

wchar_t		*ft_wstrdup(wchar_t *ws)
{
	wchar_t	*res;
	size_t	i;

	if (!ws)
		return (NULL);
	res = (wchar_t *)malloc(sizeof(wchar_t) * (ft_wstrlen(ws) + 1));
	i = -1;
	while (++i < ft_wstrlen(ws))
		res[i] = ws[i];
	return (res);
}

int			ft_wcharlen(wchar_t c)
{
	if ((int)c <= ONE_BYTE)
		return (1);
	else if ((int)c <= TWO_BYTE)
		return (2);
	else if ((int)c <= THREE_BYTE)
		return (3);
	else if ((int)c <= FOUR_BYTE)
		return (4);
	return (0);
}

size_t		ft_wstrlen(wchar_t *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len += ft_wcharlen(*s);
		s++;
	}
	return (len);
}
