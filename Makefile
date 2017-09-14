# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kromain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/17 15:05:07 by kromain           #+#    #+#              #
#    Updated: 2017/09/08 16:46:13 by kromain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

PROJECT = \
		ft_printf.c			\
		flags.c 			\
		dispatcher.c		\
		character.c			\
		string.c			\
		signed_number.c		\
		unsigned_number.c	\
		other_types.c		\
		find_width.c		\
		find_precision.c	\
		libwc.c

LIB = \
		ft_abs.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_tolower.c \
		ft_itoa.c ft_itoa_u.c ft_memset.c ft_memalloc.c ft_putchar.c \
		ft_putstr.c ft_strnew.c ft_strdel.c ft_strsub.c ft_strjoin.c \
		ft_strcmp.c ft_strlen.c ft_strdup.c ft_strchr.c ft_strcpy.c \
		ft_putdowncase.c ft_strndup.c

P_SRC = $(addprefix src/,$(PROJECT))

L_SRC = $(addprefix src/libft/,$(LIB))

SRC = $(P_SRC) $(L_SRC)

OBJ = $(PROJECT:.c=.o) $(LIB:.c=.o)

IN = -I./inc

.PHONY: all clean fclean re lib

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
	gcc $(FlAGS) $(IN) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	@echo "                              "
	@echo "\033[01;39mFinished making ft_printf. Available Makefile commands:\033[0m"
	@echo "\033[01;39m - make\033[0m"
	@echo "\033[01;39m - make clean\033[0m"
	@echo "\033[01;39m - make fclean\033[0m"
	@echo "\033[01;39m - make re\033[0m"

clean:
	@echo "                              "
	@echo "\033[01;39mCleaning ft_printf...\033[0m"
	/bin/rm -f $(OBJ)

fclean: clean
	@echo "                              "
	@echo "\033[01;31mRemoved Compiled ft_printf\033[0m"
	/bin/rm -f $(NAME) test/libft.a

re: fclean all

lib:
	gcc $(FLAGS) $(HDR) -c $(L_SRC)
	ar rc test/libft.a $(LIB:.c=.o)
	@rm -f $(OBJ)
