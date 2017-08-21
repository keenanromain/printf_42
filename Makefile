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

NAME = fractol

SRCS = \
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

all: $(NAME)

$(NAME): lib
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
	@cd src && gcc -Wall -Wextra -Werror -c $(SRCS)
	@echo "\033[01;39mFinished making ft_printf. Available Makefile commands:\033[0m"
	@echo "\033[01;39m - make\033[0m"
	@echo "\033[01;39m - make clean\033[0m"
	@echo "\033[01;39m - make fclean\033[0m"
	@echo "\033[01;39m - make re\033[0m"

lib:
	@cd libft && make

clean:
	@cd libft && make clean
	@echo "\033[01;39mCleaning ft_printf...\033[0m"
	@cd src && /bin/rm -f $(SRCS:.c=.o)

fclean: clean
	@cd libft && make fclean
	@/bin/rm -f $(NAME)
	@echo "\033[01;31mRemoved Compiled ft_printf\033[0m"

re: fclean all
