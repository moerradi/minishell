# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/06 17:30:55 by moerradi          #+#    #+#              #
#    Updated: 2021/01/06 02:44:58 by moerradi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ./srcs/config_output.c ./srcs/ft_chardup.c ./srcs/ft_printf.c \
./srcs/ft_ptoxa.c ./srcs/ft_strndup.c ./srcs/ft_uitoa.c ./srcs/ft_uitoxa.c \
./srcs/prc_width_utils.c ./srcs/set_struct.c ./srcs/utils.c

OBJS = ${SRCS:%.c=%.o}

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make bonus -C ../libft
	cp ../libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	make clean -C ../libft
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make fclean -C ../libft

re: fclean all

.PHONY: all clean fclean re
