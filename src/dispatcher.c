#include "../inc/ft_printf.h"

int		dispatch_non_numbers(va_list *args, t_flag *f)
{
	if (f->mod == l || f->spec == 'S')
		return (print_wstr(args, f, 0));
	else if (f->mod == l || f->spec == 'C')
		return (print_wchr(args, f, 0));
	else if (f->spec == 'p')
		return (print_ptr(args, f, 0));
	else if (f->spec == 's')
		return (print_str(args, f, 0));
	return (print_chr(args, f, 0));
}

static int  dispatch_unsigned_numbers(va_list *args, t_flag *f)
{
	if (f->spec == 'o' || f->spec == 'O')
	{
		f->mod = (f->spec == 'O') ? l : f->mod;
		f->spec = 'o';
		return (print_octal(f, get_unsigned(args, f)));
	}
	else if (f->spec == 'u' || f->spec == 'U')
	{
		f->mod = (f->spec == 'U') ? l : f->mod;
		f->spec = 'u';
		return (print_uint(f, get_unsigned(args, f)));
	}
	return (print_hex(f, get_unsigned(args, f)));
}

int		dispatch_numbers(va_list *args, t_flag *f)
{
	if (f->spec == 'd' || f->spec == 'D' || f->spec == 'i')
	{
		if (f->spec == 'D')
			f->mod = l;
		f->spec = 'd';
		return (print_int(f, get_signed(args, f)));
	}
	return (dispatch_unsigned_numbers(args, f));
}
