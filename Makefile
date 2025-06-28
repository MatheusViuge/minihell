NAME = minishell

LIBFT = ./lib/libft.a

DIR_BUILTINS = src/builtins

DIR_TOKEN = src/token

DIR_LEXER = src/lexer

SRC = main.c $(DIR_BUILTINS)/env/env.c $(DIR_BUILTINS)/env/utils.c $(DIR_TOKEN)/token.c $(DIR_TOKEN)/utils.c src/clear.c \
		para_excluir.c src/expand.c src/exec.c $(DIR_LEXER)/lexer.c \

OBJ_DIR = obj

OBJS := $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib
	cc -Wall -Wextra -Werror -g $(OBJS) $(LIBFT) -o $(NAME) -lreadline

$(OBJ_DIR)/%.o: %.c
	@ mkdir -p $(OBJ_DIR)
	@ mkdir -p $(OBJ_DIR)/$(DIR_BUILTINS)
	@ mkdir -p $(OBJ_DIR)/$(DIR_BUILTINS)/env
	@ mkdir -p $(OBJ_DIR)/$(DIR_TOKEN)
	@ mkdir -p $(OBJ_DIR)/$(DIR_LEXER)
	cc -Wall -Wextra -Werror -g -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C lib

fclean:
	rm -rf $(OBJ_DIR) $(NAME)
	make fclean -C lib

re: fclean all

run: all
	rm -rf $(OBJ_DIR)
	clear
	./$(NAME)

.PHONY: all clean fclean re run
