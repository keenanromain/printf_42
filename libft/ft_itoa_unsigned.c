#include "libft.h"

char	*ft_itoa_unsigned(unsigned long long n, unsigned int b)
{
	char				*s;
	int					len;
	unsigned long long	cpy;
	char				*b_str;

	b_str = ft_strdup("0123456789ABCDEF");
	cpy = n;
	len = 1;
	while (cpy >= b && len++)
		cpy = cpy / b;
	s = (char *)malloc(sizeof(char) * (++len));
	s[--len] = '\0';
	while (len--)
	{
		s[len] = b_str[n % b];
		n = n / b;
	}
	return (s);
}
