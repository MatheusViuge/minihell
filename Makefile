NAME = minishell

LIBFT = libft.a

DIR_BUILTINS = src/builtins

DIR_TOKEN = src/token

SRC = main.c $(DIR_BUILTINS)/env_utils.c $(DIR_TOKEN)/token.c $(DIR_TOKEN)/utils.c \
		para_excluir.c src/expand_variables.c src/clear.c src/exec.c

TEST_SRCS := \
	tester/test_lexer.c \
	$(DIR_BUILTINS)/env_utils.c $(DIR_TOKEN)/token.c $(DIR_TOKEN)/utils.c \
	para_excluir.c src/expand_variables.c src/clear.c src/lexer/lexer.c

TEST_NAME := test_lexer

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
	@ mkdir -p $(OBJ_DIR)/$(DIR_TOKEN)
	cc -Wall -Wextra -Werror -g -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C lib

fclean:
	rm -rf $(OBJ_DIR) $(LIBFT) $(NAME)
	make fclean -C lib

re: fclean all

run: all
	rm -rf $(OBJ_DIR)
	clear
	./$(NAME)

$(TEST_NAME):
	@echo "\n— Compilando dependências da libft —"
	@make -C lib
	@cp lib/libft.a .
	@echo "— Compilando $(TEST_NAME) —"
	@gcc -Wall -Wextra -Werror -g \
	    $(TEST_SRCS) \
	    -I./include \
	    libft.a \
	    -lreadline \
	    -o $(TEST_NAME)
	@echo "— Rodando $(TEST_NAME) —"
	@./$(TEST_NAME)
	@echo "— Fim dos testes —\n"

.PHONY: all clean fclean re run $(TEST_NAME)
