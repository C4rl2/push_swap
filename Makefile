# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cafraixe <cafraixe@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/04 16:24:58 by cafraixe          #+#    #+#              #
#    Updated: 2023/07/03 12:21:02 by cafraixe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap

HEADER_FILE			= push_swap.h

SRCS		         =	main.c \
						ft_push_swap.c \
						parsing.c \
						libft_fct.c \
						nodes.c \
						parse_dq.c \
						ft_split.c \
						rules_utils.c \
						rules1.c \
						rules2.c \
						rules3.c \
						sort_small_stack.c \
						sort_big_stack.c \

OBJS				= ${SRCS:.c=.o}

CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror
RM					= rm -f

OBJ 				= $(OBJS)
HEADER 				= $(HEADER_FILE)

$(NAME):	${OBJ}
			$(CC) $(CFLAGS) ${OBJ} -o $(NAME)

all:		${NAME}

%.o: %.c	$(HEADER)
			$(CC) -c $(CFLAGS) -o $@ $<

re: 		fclean all

clean:
			${RM} $(OBJS)

fclean:		clean
			${RM} $(NAME)

.PHONY: 	all clean fclean re