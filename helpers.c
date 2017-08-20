#include "ft_printf.h"

void	ft_putwchar(wchar_t c)
{
	if (c <= 0x7F)
		ft_putchar(c);
	else if (c <= 0x7FF)
	{
		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar((c >> 12) + 0xE0);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar((c >> 18) + 0xF0);
		ft_putchar(((c >> 12) & 0x3F) + 0x80);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
}

int		ft_wcharlen(wchar_t wc)
{
	if (wc <= 0x7F)
		return (1);
	else if (wc <= 0x7FF)
		return (2);
	else if (wc <= 0xFFFF)
		return (3);
	else if (wc <= 0x10FFFF)
		return (4);
	else
		return (0);
}

size_t	ft_wstrlen(wchar_t *ws)
{
	size_t size;
	size_t i;

	size = 0;
	i = -1;
	while (ws[++i])
		size += ft_wcharlen(ws[i]);
	return (size);
}

wchar_t	*ft_wstrdup(wchar_t *ws)
{
	wchar_t	*r;
	size_t	i;
	size_t size;

	i = -1;
	if (!ws)
		return (NULL);
	size = ft_wstrlen(ws);
	r = (wchar_t *)malloc(sizeof(wchar_t) * (size + 1));
	r[size] = '\0';
	while (++i < size)
		r[i] = ws[i];
	return (r);
}
