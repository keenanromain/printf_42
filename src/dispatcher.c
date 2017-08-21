#include "../inc/ft_printf.h"

int		dispatch_non_numbers(va_list *args, t_flag *f, int len)
{
	if (f->spec == 's' || f->spec == 'S')
	{
		if (f->mod == l || f->spec == 'S')
			len += print_wstr(args, f, len);
		else
			len += print_str(args, f, len);
	}
	else if (f->spec == 'p')
		len += print_ptr(args, f, len);
	else
	{
		if (f->mod == l || f->spec == 'C')
			len += print_wchr(args, f, len);
		else
			len += print_chr(args, f, len);
	}
	return (len);
}

static int  dispatch_unsigned_numbers(va_list *args, t_flag *f, int len)
{
	if (f->spec == 'o' || f->spec == 'O')
	{
		if (f->spec == 'O')
			f->mod = l;
		f->spec = 'o';
		len += print_octal(f, get_unsigned(args, f));
	}
	else if (f->spec == 'u' || f->spec == 'U')
	{
		if (f->spec == 'U')
			f->mod = l;
		f->spec = 'u';
		len += print_uint(f, get_unsigned(args, f));
	}
	else
		len += print_hex(f, get_unsigned(args, f));
	return (len);
}

int		dispatch_numbers(va_list *args, t_flag *f, int len)
{
	if (f->spec == 'd' || f->spec == 'D' || f->spec == 'i')
	{
		if (f->spec == 'D')
			f->mod = l;
		f->spec = 'd';
		len += print_int(f, get_signed(args, f));
	}
	else
		len += dispatch_unsigned_numbers(args, f, len);
	return (len);
}
