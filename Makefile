CC=gcc
CFLAGS=-Werror -Wall -Wextra
VPATH=sources
OBJS_DIR=objects/
SRCS=ft_printf.c ft_output_maths.c ft_output_str.c
OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
SRCS_BONUS=ft_printf_bonus.c ft_printf_utils_bonus.c maths_utils_bonus.c \
			conversions_bonus.c conversions_utils_bonus.c \
			conversions_checks_bonus.c
OBJS_BONUS=$(addprefix $(OBJS_DIR), $(SRCS_BONUS:.c=.o))
NAME=libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $@ $^
	@echo "Finished compiling ft_printf"

bonus: $(OBJS_BONUS)
	@ar -rcs $(NAME) $^
	@echo "Finished compiling ft_printf bonuses"

$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -drf $(OBJS_DIR)
	@echo "Cleaned ft_printf object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned ft_printf"

re: fclean all
	@echo "Recompiled ft_printf"

.PHONY: all clean fclean re bonus
