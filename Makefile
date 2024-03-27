# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 14:39:30 by mbankhar          #+#    #+#              #
#    Updated: 2024/03/25 09:19:42 by mbankhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_print_char.c ft_print_digit.c ft_print_digitup.c \
ft_print_digitptr.c ft_print_str.c 

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	
$(OBJ): %.o: %.c $(HEADER)
	cc $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re


