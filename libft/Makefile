# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kromain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 13:51:22 by kromain           #+#    #+#              #
#    Updated: 2017/06/26 09:43:33 by kromain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = \
		ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memccpy.c	\
		ft_memmove.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_strdup.c		\
		ft_strcpy.c		\
		ft_strncpy.c	\
		ft_strcat.c		\
		ft_strncat.c	\
		ft_strlcat.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strstr.c		\
		ft_strnstr.c	\
		ft_strcmp.c		\
		ft_strncmp.c	\
		ft_atoi.c		\
		ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_memalloc.c	\
		ft_memdel.c		\
		ft_strnew.c		\
		ft_strdel.c		\
		ft_strclr.c		\
		ft_striter.c	\
		ft_striteri.c	\
		ft_strmap.c		\
		ft_strmapi.c	\
		ft_strequ.c		\
		ft_strnequ.c	\
		ft_strsub.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_strsplit.c	\
		ft_itoa.c		\
		ft_putchar.c	\
		ft_putstr.c		\
		ft_putendl.c	\
		ft_putnbr.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_lstadd.c		\
		ft_lstdel.c		\
		ft_lstdelone.c	\
		ft_lstiter.c	\
		ft_lstnew.c		\
		ft_lstmap.c		\
		ft_strndup.c	\
		ft_atol.c		\
		ft_strclen.c	\
		ft_lstsize.c	\
		ft_isspace.c	\
		ft_atoi_array.c	\
		ft_numcount.c	\
		ft_numlen.c		\
		ft_abs.c		\
		ft_strcdup.c	\
		ft_exp.c		\
		ft_sqrt.c		\
		ft_isprime.c	\
		ft_swap.c		\
		ft_pow.c		\
		ft_strccpy.c	\
		ft_strcjoin.c	\
		ft_revsign.c	\
		ft_downcase.c	\
		ft_upcase.c		\
		ft_strnchr.c	\
		ft_putnstr.c	\
		get_next_line.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@echo "\033[01;36mCompiling...\033[0m"
	@gcc -Wall -Werror -Wextra -c $(SRCS)
	@ar rcs $(NAME) $(OBJS)
	@echo "\033[01;36m _      ____  ____   _____  ______ \033[0m"
	@echo "\033[01;36m| |    |    ||    \ |     ||      |\033[0m"
	@echo "\033[01;36m| |     |  | |  o  )|   __||      |\033[0m"
	@echo "\033[01;36m| |___  |  | |     ||  |_  |_|  |_|\033[0m"
	@echo "\033[01;36m|     | |  | |  O  ||   _]   |  |  \033[0m"
	@echo "\033[01;36m|     | |  | |     ||  |     |  |  \033[0m"
	@echo "\033[01;36m|_____||____||_____||__|     |__|  \033[0m"
                                  

clean:
	@echo "\033[01;39mCleaning Libft...\033[0m"
	@rm -f $(OBJS)

fclean:
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@echo "\033[01;31mRemoved Compiled Libft\033[0m"

re: clean fclean all
