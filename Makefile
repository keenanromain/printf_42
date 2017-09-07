# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kromain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/27 15:05:07 by kromain           #+#    #+#              #
#    Updated: 2017/04/28 14:28:58 by kromain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

FLAGS = -Wall -Werror -Wextra

FILES = \
		ft_printf.c			\
		flags.c				\
		dispatcher.c		\
		characters.c		\
		strings.c			\
		signed_numbers.c	\
		unsigned_numbers.c	\
		pointers.c			\
		miscellaneous.c		\
		helpers.c			\
		handle_width.c		\
		handle_precision.c

LIBFT = \
		ft_memset.c			\
		ft_bzero.c			\
		ft_memcpy.c			\
		ft_memccpy.c		\
		ft_memmove.c		\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_strlen.c			\
		ft_strdup.c			\
		ft_strcpy.c			\
		ft_strncpy.c		\
		ft_strcat.c			\
		ft_strncat.c		\
		ft_strlcat.c		\
		ft_strchr.c			\
		ft_strrchr.c		\
		ft_strstr.c			\
		ft_strnstr.c		\
		ft_strcmp.c			\
		ft_strncmp.c		\
		ft_atoi.c			\
		ft_isalpha.c		\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_memalloc.c		\
		ft_memdel.c			\
		ft_strnew.c			\
		ft_strdel.c			\
		ft_strclr.c			\
		ft_striter.c		\
		ft_striteri.c		\
		ft_strmap.c			\
		ft_strmapi.c		\
		ft_strequ.c			\
		ft_strnequ.c		\
		ft_strsub.c			\
		ft_strjoin.c		\
		ft_strtrim.c		\
		ft_strsplit.c		\
		ft_itoa.c			\
		ft_putchar.c		\
		ft_putstr.c			\
		ft_putendl.c		\
		ft_putnbr.c			\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c		\
		ft_lstadd.c			\
		ft_lstdel.c			\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstnew.c			\
		ft_lstmap.c			\
		ft_strndup.c		\
		ft_atol.c			\
		ft_strclen.c		\
		ft_lstsize.c		\
		ft_isspace.c		\
		ft_atoi_array.c		\
		ft_numcount.c		\
		ft_numlen.c			\
		ft_abs.c			\
		ft_strcdup.c		\
		ft_exp.c			\
		ft_sqrt.c			\
		ft_isprime.c		\
		ft_swap.c			\
		ft_pow.c			\
		ft_strccpy.c		\
		ft_strcjoin.c		\
		ft_revsign.c		\
		ft_downcase.c		\
		ft_upcase.c			\
		ft_strnchr.c		\
		ft_putnstr.c		\
		ft_itoa_unsigned.c	\
		get_next_line.c

F_SRCS = $(addprefix src/,$(FILES))
L_SRCS = $(addprefix libft/,$(LIBFT))

PROJECT = $(F_SRCS) $(L_SRCS)
OBJECTS = $(F_SRCS:.c=.o) $(L_SRCS:.c=.o)

.PHONY: all clean fclean re test lib

all: $(NAME)

$(NAME):
	@echo "                              "
	@echo "\033[01;36mCompiling..."
	@echo "  __ _                  _       _    __ "
	@echo " / _| |                (_)     | |  / _|"
	@echo "| |_| |_     _ __  _ __ _ _ __ | |_| |_ "
	@echo "|  _| __|   | '_ \| '__| | '_ \| __|  _|"
	@echo "| | | |_    | |_) | |  | | | | | |_| |  "
	@echo "|_|  \__|   | .__/|_|  |_|_| |_|\__|_|  "
	@echo "      ______| |                         "
	@echo "     |______|_|            \033[0m "
	gcc $(FLAGS) -I./inc -c $(PROJECT)
	@mv -f *.o obj/
	@echo "\033[01;39mFinished making ft_printf. Available Makefile commands:\033[0m"
	@echo "\033[01;39m - make\033[0m"
	@echo "\033[01;39m - make clean\033[0m"
	@echo "\033[01;39m - make fclean\033[0m"
	@echo "\033[01;39m - make re\033[0m"

test:
	gcc $(FLAGS) -I./inc $(PROJECT) test/main.c -L test/libft.a -o test/a.out
	./test/a.out
	@rm -f $(OBJECTS)

clean:
	@echo "\033[01;39mCleaning ft_printf...\033[0m"
	@rm -f obj/*.o

fclean: clean
	@rm -f $(NAME)
	@echo "\033[01;31mRemoved Compiled ft_printf\033[0m"

re: fclean all

lib:
	gcc $(FLAGS) -I./inc -c $(L_SRCS)
	ar rc test/libft.a $(LIBFT:.c=.o)
	@rm -f $(OBJECTS)
