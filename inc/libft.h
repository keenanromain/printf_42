/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 10:52:13 by kromain           #+#    #+#             */
/*   Updated: 2017/08/10 12:51:26 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdint.h>


typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	int				fd;
}					t_list;

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_tolower(int c);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putdowncase(char *s);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
ptrdiff_t			ft_abs(ptrdiff_t n);
char				*ft_itoa(ptrdiff_t n);
int					ft_atoi(const char *str);
char				*ft_itoa_u(unsigned long long nb, unsigned int base);

#endif
