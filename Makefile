NAME = push_swap

SRC_DIR = src

SOURCES = main.c operations.c parse.c push.c rotate.c swap.c utils.c

OBJ_DIR = obj

OBJECT = $(SOURCES:.c=.o)

OBJECTS = $(addprefix $(OBJ_DIR)/, $(OBJECT))

LIBFT_DIR = ./Libft

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc

CFLAGS = -g -Wall -Werror -Wextra -fsanitize=address

RMFLAGS = -rf

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :  
	make -C $(LIBFT_DIR) bonus

clean :
	rm $(RMFLAGS) $(OBJECTS)
	make -C $(LIBFT_DIR) clean 

fclean : clean
	rm $(RMFLAGS) $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

PHONY = all clean fclean re

