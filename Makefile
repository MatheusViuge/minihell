NAME = minishell

LIBFT = libft.a

DIR_BUILTINS = src/builtins

SRC = main.c $(DIR_BUILTINS)/env_utils.c

OBJ_DIR = obj

OBJS := $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib
	cp lib/$(LIBFT) .
	cc -Wall -Wextra -Werror -g $(OBJS) $(LIBFT) -o $(NAME) -lreadline

$(OBJ_DIR)/%.o: %.c
	@ mkdir -p $(OBJ_DIR)
	@ mkdir -p $(OBJ_DIR)/$(DIR_BUILTINS)
	cc -Wall -Wextra -Werror -g -c $< -o $@ -lreadline

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
