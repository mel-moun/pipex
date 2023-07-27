# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 16:40:20 by mel-moun          #+#    #+#              #
#    Updated: 2023/03/10 17:36:34 by mel-moun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=pipex

CC=cc

FLAG=-Wall -Werror -Wextra

SRC=child.c \
	command.c \
	error.c \
	parent.c \
	path.c \
	pipex_utils.c \
	pipex_utils1.c \
	pipex.c

OBJ=${SRC:.c=.o}

all: $(NAME)

%.o: %.c
	${CC} ${FLAG} -c $<

${NAME}: ${OBJ}
	${CC} ${FLAG} $^ -o $@

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean all

.PHONY: clean fclean all re
