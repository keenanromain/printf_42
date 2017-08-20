#ifndef FT_PRINTF
# define FT_PRINTF

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdbool.h>
# include <stddef.h>
# include "libft/libft.h"

typedef enum		s_mod
{
	h,
	hh,
	l,
	ll,
	j,
	z,
	t,
	no
}					t_mod;

typedef struct		s_flag
{
	bool			hash;
	bool			zero;
	bool			minus;
	bool			space;
	bool			plus;
	int				amount;
	unsigned int	len;
	unsigned int	precision;
	int				width;
	char			spec;
	int				new_w;
	int				new_p;
	t_mod			mod;
}					t_flag;


int					ft_printf(const char *format, ...);
int					run_thru_string(char *format, va_list *args, t_flag *f);
int					next_char(va_list *args, char *s, t_flag *f, int size);
int					parse_valid(va_list *args, t_flag *f, char *s, char *check, char *comp);
int					flags(t_flag *f, char *s, va_list *args, int i);
int					conversions(t_flag *f, va_list *args, int len);
int					dispatch_numbers(va_list *args, t_flag *f, int len);
int					dispatch_non_numbers(va_list *args, t_flag *f, int len);
int					print_percent(t_flag *f);
int					print_invalid(t_flag *f);
int					print_chr(va_list *args, t_flag *f, int len);
int					print_wchr(va_list *args, t_flag *f, int len);
int					print_str(va_list *args, t_flag *f, int len);
int					print_wstr(va_list *args, t_flag *f, int len);
int					print_ptr(va_list *args, t_flag *f, int len);
int					print_int(va_list *args, t_flag *f, intmax_t type);
int					print_octal(va_list *args, t_flag *f, unsigned long long type);
int					print_uint(va_list *args, t_flag *f, unsigned long long type);
int					print_hex(va_list *args, t_flag *f, unsigned long long type);
unsigned long long	get_unsigned(va_list *args, t_flag *f);
intmax_t			get_signed(va_list *args, t_flag *f);
void				ft_putwchar(wchar_t c);
int					ft_wcharlen(wchar_t wc);
size_t				ft_wstrlen(wchar_t *ws);
wchar_t				*ft_wstrdup(wchar_t *ws);

#endif
