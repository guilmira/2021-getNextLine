# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 11:57:39 by guilmira          #+#    #+#              #
#    Updated: 2021/09/13 15:20:23 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------------------------------------------------------------------------COMPILER
NAME	= gnl.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
OBJS	= $(SRCS:.c=.o)
INCLUDES	= -I ./0includes
#-g3 -fsanitize=address

#--------------------------------------------------------------------------------------------------------------SOURCES
SRCS = get_next_line.c get_next_line_utils.c main.c
#--------------------------------------------------------------------------------------------------------------RULES

all: $(NAME)

%.o: %.c
	-@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs ${NAME} ${OBJS}
#@$(CC) -o $(NAME) $(SRCS) && ./$(NAME)
m:
	$(CC) $(FLAGS) $(OBJS) && ./a.out

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
