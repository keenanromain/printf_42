/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/14/08 26:45:21 by kromain           #+#    #+#             */
/*   Updated: 2017/19/08 11:21:28 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPEC "sSpdDioOuUxXcC%"
# define POSS "sSpdDioOuUxXcC%hljz"
# define ONE_BYTE 127
# define TWO_BYTE 2047
# define THREE_BYTE 65535

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"
# include <stdbool.h>
# include <wchar.h>

typedef enum		e_mod
{
	no,
	h,
	hh,
	l,
	ll,
	j,
	z,
	t
}					t_mod;

typedef struct		s_flags
{
	bool			pound;
	bool			zero;
	bool			minus;
	bool			space;
	bool			plus;
	bool			set_width;
	bool			set_prec;
	int				width;
	unsigned int	prec;
	unsigned int	len;
	t_mod			mod;
	char			spec;
}					t_flags;

int					ft_printf(const char *format, ...);
int					determine_flags(char *fmt, va_list *av);
int					dispatcher(t_flags *f, va_list *av);
int					dispatch_non_number(t_flags *f, va_list *av);
int					dispatch_number(t_flags *f, va_list *av);
int					print_c(t_flags *f, va_list *av, int len);
int					print_s(t_flags *f, va_list *av, int len);
int					print_wc(t_flags *f, va_list *av, int len);
int					print_ws(t_flags *f, va_list *av, int len);
int					print_signed(t_flags *f, intmax_t type);
int					print_octal(t_flags *f, unsigned long long type);
int					print_unsigned(t_flags *f, unsigned long long type);
int					print_hex(t_flags *f, unsigned long long type);
int					print_pointer(t_flags *f, va_list *av);
int					print_percent(t_flags *f, va_list *av);
int					print_invalid(t_flags *f);
intmax_t			signed_type(t_flags *f, va_list *av);
unsigned long long	unsigned_type(t_flags *f, va_list *av);
int					i_width(unsigned int i, t_flags *f);
void				s_width(char **s, t_flags *f);
int					ws_width(wchar_t **ws, t_flags *f);
void				i_precision(char **s, t_flags *f);
void				s_precision(char **s, t_flags *f);
void				ws_precision(wchar_t **ws, t_flags *f);
int					ft_wcharlen(wchar_t c);
size_t				ft_wstrlen(wchar_t *s);
wchar_t				*ft_wstrdup(wchar_t *ws);
void				wc_to_s(wchar_t wc, char *s);
char				*ws_to_s(wchar_t *ws, size_t len, int i);

#endif
