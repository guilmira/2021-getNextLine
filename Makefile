# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 11:57:39 by guilmira          #+#    #+#              #
#    Updated: 2021/06/08 12:35:14 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRCS = get_next_line.c get_next_line_utils.c main.c
OBJS = $(SRCS:.c=.o)
CC = gcc -Wall -Werror -Wextra
CCDEB = gcc -g -Wall -Werror -Wextra
#CCDEB = gcc -g -Wall -Werror -Wextra -D BUFFER_SIZE=$(NBR)
NBR		= 400000


all: $(NAME)
$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(SRCS) && ./$(NAME)
m:
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$(NBR) $(SRCS) && ./$(NAME)
deb: $(OBJS)
	$(CCDEB) $(SRCS)
clean:
	@rm $(OBJS)
fclean: clean
	@rm $(NAME)
re: fclean all
