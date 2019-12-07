# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daprovin <daprovin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 21:13:16 by daprovin          #+#    #+#              #
#    Updated: 2019/12/07 05:37:25 by daprovin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

OBJS := \
	src/ft_printf.o \
	src/ft_printf_utils.o \
	src/ft_printing_types.o \
	src/ft_printing_type_int.o \
	src/ft_printing_type_uint.o \
	src/ft_printing_type_hex.o \
	src/ft_printing_type_point.o \

GFLAGS := -Wall -Werror -Wextra
HEAD := libft/
HEAD2 := libftprintf.h

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C libft
	cp libft/libft.a . && ar q libft.a $(OBJS) && mv libft.a $(NAME)

%.o: %.c
	gcc -I $(HEAD) -I $(HEAD2) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

