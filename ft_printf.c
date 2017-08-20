#include "ft_printf.h"


int		parse_valid(va_list *args, t_flag *f, char *s, char *check, char *comp)
{
	char		*tmp;
	int i;
	char *p;

	tmp = s;
	i = -1;
	p = NULL;
	while (tmp[++i])
	{
		if (ft_strchr(comp, tmp[i]) || ft_isalpha(tmp[i]) || \
				!ft_strchr(check, tmp[i]))
		{
			p = ft_strndup(s, ++i);
			break ;
		}
	}
	return (p == NULL ? 0 : flags(f, s, args, -1));
}

int		next_char(va_list *args, char *s, t_flag *f, int size)
{
	char		*comp;
	char		*check;

	comp = ft_strdup("sSpdDioOuUxXcC%");
	check = ft_strdup("sSpdDioOuUxXcC%hljz");
	if (*s)
		size += parse_valid(args, f, s, check, comp);
	return (size);
}

int		run_thru_string(char *format, va_list *args, t_flag *f)
{
	int			size;
	char		*s;
	char		*last_spot;

	size = 0;
	s = format;
	last_spot = s;
	while (*s)
	{
		if (*s == '%')
		{
			ft_putnstr(last_spot, s - last_spot);
			size += next_char(args, s++, f, 0);
			s += size;
			last_spot = s;
			continue ;
		}
		size++;
		s++;
	}
	ft_putnstr(last_spot, s - last_spot);
	return (size);
}

int		ft_printf(const char *format, ...)
{
	int			size;
	va_list		args;
	t_flag		*f;

	if (!format)
		return (0);
	f = (t_flag *)malloc(sizeof(t_flag));
	ft_memset(f, 0, sizeof(t_flag));
	va_start(args, format);
	size = run_thru_string((char *)format, &args, f);
	va_end(args);
	return (size);
}
