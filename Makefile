NAME = minishell

LIBFT = ./lib/libft.a

DIR_BUILTINS = src/builtins

DIR_TOKEN = src/token

DIR_LEXER = src/lexer

DIR_PARSER = src/Parser

BOLD = \033[1m
RESET = \033[0m
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m

SRC = main.c $(DIR_BUILTINS)/env/env.c $(DIR_BUILTINS)/env/utils.c $(DIR_TOKEN)/token.c $(DIR_TOKEN)/utils.c \
		src/expand.c src/clear.c src/exec.c $(DIR_LEXER)/lexer.c src/utils.c src/error.c \
		$(DIR_PARSER)/parser_main.c $(DIR_PARSER)/ast_handler.c $(DIR_PARSER)/ast_errors.c \
		$(DIR_PARSER)/ast_utils.c $(DIR_PARSER)/testes.c $(DIR_BUILTINS)/export.c $(DIR_BUILTINS)/unset.c \
		$(DIR_BUILTINS)/pwd.c $(DIR_BUILTINS)/cd.c $(DIR_BUILTINS)/exit.c 

OBJ_DIR = obj

OBJS := $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ make -C lib
	@ cp $(LIBFT) .
	@ cc -Wall -Wextra -Werror -g $(OBJS) $(LIBFT) -o $(NAME) -lreadline
	@ clear
	@ echo "$(GREEN)Compilado com sucesso!$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@ mkdir -p $(OBJ_DIR)
	@ mkdir -p $(OBJ_DIR)/$(DIR_BUILTINS)
	@ mkdir -p $(OBJ_DIR)/$(DIR_BUILTINS)/env
	@ mkdir -p $(OBJ_DIR)/$(DIR_TOKEN)
	@ mkdir -p $(OBJ_DIR)/$(DIR_LEXER)
	@ mkdir -p $(OBJ_DIR)/$(DIR_PARSER)
	@ clear
	@ echo "$(YELLOW)$(BOLD)Compilando $<"
	@ cc -Wall -Wextra -Werror -g -c $< -o $@

clean:
	@ rm -rf $(OBJ_DIR)
	@ make clean -C lib
	@ clear
	@ echo "$(RED)$(BOLD)Arquivos objeto removidos!$(RESET)"

fclean:
	@ rm -rf $(OBJ_DIR) $(LIBFT) $(NAME)
	@ make fclean -C lib
	@ clear
	@ echo "$(RED)$(BOLD)Arquivos objetos e ./minishell removidos!$(RESET)"

re: fclean all

run: all
	rm -rf $(OBJ_DIR)
	clear
	./$(NAME)

.PHONY: all clean fclean re run
