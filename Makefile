NAME = push_swap
LIBFT_DIR = ./utils/libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = gcc -g
FLAGS = -Wall -Werror -Wextra
INCLUDE = -I ./include
OBJ_FILES = $(SRC:%.c=%.o)
SRC =	./src/push_swap.c \
		./src/create_list.c \
		./src/push_swap_utils.c \
		./src/op_swap_push.c  \
		./src/op_rotate.c \
		./src/op_reverse.c \
		./src/algo_max5.c \
		./src/is_sorted.c \
		./src/push_swap_index.c

all : $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)
	gcc $(OBJ_FILES) $(LIBFT) -o $(NAME) 

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo "Cleaning up .o files"
	$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(OBJ_FILES)

fclean: clean
	@echo "We are cleaning now"
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
