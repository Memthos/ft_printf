SRCS_DIR=sources/
OBJS_DIR=objects/
HEADERS=headers/
SRCS=ft_printf.c ft_output_maths.c ft_output_str.c
OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
CC=cc
CFLAGS=-Werror -Wall -Wextra
NAME=libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $@ $^
	@echo "Finished compiling ft_printf"

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -drf $(OBJS_DIR)
	@echo "Cleaned ft_printf object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned ft_printf"

re: fclean all
	@echo "Recompiled ft_printf"

.PHONY: all clean fclean re
