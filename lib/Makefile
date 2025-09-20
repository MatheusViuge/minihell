NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_isspace.c ft_lstnew.c \
	ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstclear.c \
	ft_dbl_lstnew.c ft_dbl_lstadd_front.c ft_dbl_lstsize.c ft_dbl_lstlast.c \
	ft_dbl_lstadd_back.c ft_dbl_lstdelone.c ft_dbl_lstiter.c ft_dbl_lstmap.c ft_dbl_lstclear.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c ft_strcspn.c ft_lstswap.c ft_dbl_lstswap.c \
	ft_atol.c ft_strchr_nbr.c ft_join_args.c ft_strnrchr_nbr.c free_split.c \
	printf/ft_printf.c printf/print_char.c printf/print_str.c printf/print_pointer.c printf/print_nbr.c printf/print_unsigned.c \
	printf/print_hex.c printf/print_uns_long_hex.c \
	sprintf/ft_sprintf.c sprintf/malloc_char.c sprintf/malloc_str.c sprintf/malloc_pointer.c sprintf/malloc_nbr.c sprintf/malloc_unsigned.c \
	sprintf/malloc_hex.c sprintf/malloc_uns_long_hex.c sprintf/utils.c

OBJ_DIR = obj

OBJS := $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c
	@ mkdir -p $(OBJ_DIR)
	@ mkdir -p $(OBJ_DIR)/sprintf
	@ mkdir -p $(OBJ_DIR)/printf
	@ mkdir -p $(OBJ_DIR)/gnl
	cc -Wall -Wextra -Werror -g -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
