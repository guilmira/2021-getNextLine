# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 11:57:39 by guilmira          #+#    #+#              #
#    Updated: 2021/06/05 15:11:11 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
CC = gcc -Wall -Werror -Wextra
CCDEB = gcc -g -Wall -Werror -Wextra
NBR		= 32

all: $(NAME)
$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(SRCS) && ./$(NAME)
buff:
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$(NBR) get_next_line.c get_next_line_utils.c && ./$(NAME)
deb: $(OBJS)
	$(CCDEB) $(SRCS)
clean:
	@rm $(OBJS)
fclean: clean
	@rm $(NAME)
re: fclean all
