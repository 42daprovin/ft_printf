# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daprovin <daprovin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 21:13:16 by daprovin          #+#    #+#              #
#    Updated: 2019/11/22 08:34:06 by daprovin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

OBJS := \
	src/

GFLAGS := -Wall -Werror -Wextra
HEAD := libft/libft.h printf.h

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C libft
	cp libft/libft.a . && ar q libft.a $(OBJS) && mv libft.a $(NAME)

%.o: %.c
	gcc $(GFLAGS) -I $(HEAD) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

