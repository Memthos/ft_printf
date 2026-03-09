SRCS_DIR=sources/
OBJS_DIR=objects/
HEADERS=includes/
SRCS=ft_bzero.c ft_calloc.c ft_isdigit.c ft_memset.c ft_strlcpy.c ft_strdup.c \
	ft_strlcat.c ft_strlen.c ft_strncpy.c
OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
CC=cc
CFLAGS=-Wall -Wextra -Werror -I$(HEADERS)
NAME=libft_tools.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $@ $^
	@echo "Finished compiling libft"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -drf $(OBJS_DIR)
	@echo "Cleaned libft object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned libft"

re: fclean all
	@echo "Recompiled libft"

.PHONY: all clean fclean re
