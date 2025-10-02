NAME = libft.a

DIR_INCLUDE = ./include

DIR_OBJ = ./obj

DIR = $(DIR_OBJ) \
	$(DIR_OBJ)/gnl \
	$(DIR_OBJ)/sprintf \
	$(DIR_OBJ)/printf

SRC = 	ft_substr.c \
	ft_dbl_lstdelone.c \
	ft_lstiter.c \
	ft_lstswap.c \
	ft_atoi.c \
	ft_strrchr.c \
	ft_strdup.c \
	ft_strmapi.c \
	ft_lstmap.c \
	ft_strchr_nbr.c \
	ft_dbl_lstadd_front.c \
	ft_dbl_lstiter.c \
	ft_memset.c \
	ft_strnstr.c \
	ft_striteri.c \
	ft_toupper.c \
	ft_isprint.c \
	ft_putnbr_fd.c \
	free_split.c \
	ft_strlen.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_isalpha.c \
	ft_isalnum.c \
	ft_memchr.c \
	ft_lstlast.c \
	ft_putendl_fd.c \
	ft_itoa.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_atol.c \
	sprintf/malloc_unsigned.c \
	sprintf/malloc_pointer.c \
	sprintf/malloc_hex.c \
	sprintf/malloc_nbr.c \
	sprintf/ft_sprintf.c \
	sprintf/utils.c \
	sprintf/malloc_str.c \
	sprintf/malloc_uns_long_hex.c \
	sprintf/malloc_char.c \
	ft_dbl_lstnew.c \
	ft_strlcpy.c \
	ft_strchr.c \
	ft_memmove.c \
	ft_split.c \
	ft_join_args.c \
	ft_isspace.c \
	ft_dbl_lstswap.c \
	ft_dbl_lstsize.c \
	ft_putchar_fd.c \
	ft_lstadd_back.c \
	ft_strtrim.c \
	ft_dbl_lstlast.c \
	ft_strlcat.c \
	ft_dbl_lstadd_back.c \
	ft_strjoin.c \
	ft_strcspn.c \
	ft_tolower.c \
	ft_isdigit.c \
	ft_strnrchr_nbr.c \
	ft_isascii.c \
	printf/print_char.c \
	printf/print_pointer.c \
	printf/print_uns_long_hex.c \
	printf/print_unsigned.c \
	printf/print_str.c \
	printf/print_hex.c \
	printf/ft_printf.c \
	printf/print_nbr.c \
	ft_strncmp.c \
	ft_lstnew.c \
	ft_putstr_fd.c \
	ft_lstadd_front.c \
	ft_calloc.c \
	ft_lstsize.c \
	ft_dbl_lstclear.c \
	ft_bzero.c \
	ft_dbl_lstmap.c

OBJS := $(addprefix $(DIR_OBJ)/,$(SRC:%.c=%.o))

BLINKING = \033[5m
RESET = \033[0m
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[1;33m

all: $(NAME)

$(NAME): $(OBJS)
	@ ar -rcs $(NAME) $(OBJS)
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
	@ clear
	@ echo "$(RED)Object files removed!$(RESET)"

fclean:
	@ rm -rf $(DIR_OBJ) $(NAME)
	@ clear
	@ echo "$(RED)Object files and $(NAME) removed!$(RESET)"

re: fclean all

run: all clean
	./$(NAME)

.PHONY: all clean fclean re run $(NAME)
