# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 21:58:52 by gholloco          #+#    #+#              #
#    Updated: 2024/04/12 18:05:18 by gholloco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

SRC_DIR = src

SOURCES = free.c main.c move.c parse.c push.c rotate.c sort.c sort_into_a.c sort_into_b.c swap.c utils.c

SOURCES_CHECKER = checker.c free.c parse.c rotate.c swap.c push.c utils.c

OBJ_DIR = obj

OBJECT = $(SOURCES:.c=.o)

OBJECT_CHECKER = $(SOURCES_CHECKER:.c=.o)

OBJECTS = $(addprefix $(OBJ_DIR)/, $(OBJECT))

OBJECTS_CHECKER = $(addprefix $(OBJ_DIR)/, $(OBJECT_CHECKER))

LIBFT_DIR = ./includes/Libft

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc

CFLAGS = -g -Wall -Werror -Wextra

RMFLAGS = -rf

all : $(OBJ_DIR) $(NAME)

bonus : $(OBJ_DIR) $(CHECKER)

$(NAME) : $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(CHECKER) : $(OBJECTS_CHECKER) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(LIBFT) :  
	make -C $(LIBFT_DIR) bonus

clean :
	rm $(RMFLAGS) $(OBJECTS) $(OBJECTS_CHECKER)
	make -C $(LIBFT_DIR) clean 

fclean : clean
	rm $(RMFLAGS) $(NAME) $(CHECKER)
	make -C $(LIBFT_DIR) fclean

re : fclean all

PHONY = all clean fclean re

