#include "ft_printf.h"

unsigned long long		get_unsigned(va_list *args, t_flag *f)
{
	if (f->mod == h)
		return (unsigned long long)(unsigned short)va_arg(*args, unsigned int);
	else if (f->mod == hh)
		return (unsigned long long)(unsigned int)va_arg(*args, unsigned int);
	else if (f->mod == l)
		return (unsigned long long)va_arg(*args, unsigned long);
	else if (f->mod == ll)
		return (unsigned long long)va_arg(*args, unsigned long long);
	else if (f->mod == no)
		return (unsigned long long)va_arg(*args, unsigned int);
	else if (f->mod == j)
		return (unsigned long long)va_arg(*args, uintmax_t);
	else if (f->mod == z)
		return (unsigned long long)va_arg(*args, size_t);
	else if (f->mod == t)
		return (unsigned long long)va_arg(*args, unsigned long long);
	else
		return (0);
}
