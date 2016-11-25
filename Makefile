# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srabah-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/23 23:17:31 by srabah-m          #+#    #+#              #
#    Updated: 2014/03/23 22:11:29 by srabah-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
NAME	= lem-in
CFLAGS	= -Wall -Werror -Wextra -Iincludes/
SRC 	=	display_1.c display_2.c display_3.c display_4.c	\
			ft_atoi.c ft_errors.c ft_itoa.c ft_strings.c ft_strings_2.c	\
			get_next_line.c main.c manage_graph.c manage_queue_1.c \
			move.c move_2.c
OBJ		= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) -o $@  $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
