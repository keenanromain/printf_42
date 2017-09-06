#include "../inc/ft_printf.h"


static int		parse_format(va_list *args, t_flag *f, char *s, int *size)
{
	char	*tmp;
	int		i;
	char	*p;

	tmp = s;
	i = -1;
	p = NULL;
	while (tmp[++i])
	{
		if (ft_strchr(SET, tmp[i]) || ft_isalpha(tmp[i]) || \
				!ft_strchr(UNSET, tmp[i]))
		{
			p = ft_strndup(s, ++i);
			break ;
		}
	}
	if (!p)
		return (0);
	*size += flags(f, s, args, -1);
	return (i);
}
int			run_thru_string(char *s, va_list *args, t_flag *f, int *size)
{
	int *ptr;

	ptr = 0;
	while (*s)
	{
		if (*s == '%' && s++)
		{
			if (*s == 'n')
			{
				ptr = va_arg(*args, int*);
				*ptr = *size;
				s++;
			}
			else
				s += parse_format(args, f, s, size);
		}
		else
			*size += write(1, s++, 1);
	}
	return (*size);
}

int			ft_printf(const char *format, ...)
{
	int			size;
	va_list		args;
	t_flag		*f;

	size = 0;
	if (!format)
		return (size);
	f = (t_flag *)malloc(sizeof(t_flag));
	ft_memset(f, 0, sizeof(t_flag));
	va_start(args, format);
	size = run_thru_string((char *)format, &args, f , &size);
	va_end(args);
	return (size);
}
