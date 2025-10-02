NAME = minishell

DIR_INCLUDE = ./include

DIR_LIB = ./lib

LIBFT = $(DIR_LIB)/libft.a

DIR_OBJ = ./obj

DIR = $(DIR_OBJ) \
	$(DIR_OBJ)/src \
	$(DIR_OBJ)/src/Parser \
	$(DIR_OBJ)/src/lexer \
	$(DIR_OBJ)/src/builtins \
	$(DIR_OBJ)/src/builtins/env \
	$(DIR_OBJ)/src/token \
	$(DIR_OBJ)/src/execucao \
	$(DIR_OBJ)/src/expand \
	$(DIR_OBJ)/src/redirects

SRC = 	main.c \
	src/Parser/parser_main.c \
	src/Parser/ast_utils.c \
	src/Parser/ast_errors.c \
	src/Parser/ast_handler.c \
	src/signal.c \
	src/lexer/lexer.c \
	src/builtins/echo.c \
	src/builtins/unset.c \
	src/builtins/cd.c \
	src/builtins/pwd.c \
	src/builtins/exit.c \
	src/builtins/env/env.c \
	src/builtins/env/utils.c \
	src/builtins/export.c \
	src/clear.c \
	src/token/token.c \
	src/token/utils.c \
	src/utils.c \
	src/execucao/exec_handler.c \
	src/execucao/path_utils.c \
	src/execucao/exec_utils.c \
	src/execucao/pid_handler.c \
	src/error.c \
	src/exec.c \
	src/expand/expand.c \
	src/expand/utils.c \
	src/redirects/pipe_handler.c \
	src/redirects/redirect_handler.c

OBJS := $(addprefix $(DIR_OBJ)/,$(SRC:%.c=%.o))

ADD_FLAGS_COMPILE_PROGRAM = -lreadline

BLINKING = \033[5m
RESET = \033[0m
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[1;33m

all: $(NAME)

$(NAME): $(OBJS)
	@ make -C $(DIR_LIB)
	@ cc -Wall -Wextra -Werror -g $(OBJS) $(LIBFT) -o $(NAME) $(ADD_FLAGS_COMPILE_PROGRAM)
	@ clear
	@ echo "$(GREEN)Compiled successfully!$(RESET)"

$(DIR_OBJ)/%.o: %.c $(DIR_OBJ)
	@ echo "$(YELLOW)Compiling $<$(RESET)"
	@ cc -Wall -Wextra -Werror -g -c $< -o $@

$(DIR_OBJ):
	@ mkdir -p $(DIR)
	@ echo "$(YELLOW)Object directories created!$(RESET)"

clean:
	@ rm -rf $(DIR_OBJ)
	@ make clean -C $(DIR_LIB)
	@ clear
	@ echo "$(RED)Object files removed!$(RESET)"

fclean:
	@ rm -rf $(DIR_OBJ) $(NAME)
	@ make fclean -C $(DIR_LIB)
	@ clear
	@ echo "$(RED)Object files and $(NAME) removed!$(RESET)"

re: fclean all

run: all clean
	./$(NAME)

.PHONY: all clean fclean re run $(NAME)

