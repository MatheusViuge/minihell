NAME = minishell

SRC = main.c

LIBFT = libft.a

OBJ_DIR = obj

OBJS := $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib
	cp lib/$(LIBFT) .
	cc -Wall -Wextra -Werror -g $(OBJS) $(LIBFT) -o $(NAME) 

$(OBJ_DIR)/%.o: %.c
	@ mkdir -p $(OBJ_DIR)
	@ mkdir -p $(OBJ_DIR)/src
	@ mkdir -p $(OBJ_DIR)/src/utils
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C lib

fclean:
	rm -rf $(OBJ_DIR) $(LIBFT) $(NAME)
	make fclean -C lib

re: fclean all

run: all clean
	clear

.PHONY: all clean fclean re run
