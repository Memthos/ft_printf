CC=gcc
CFLAGS=-Werror -Wall -Wextra -I $(INCLUDES)
VPATH=srcs
INCLUDES=includes/
OBJS_DIR=objs/
SRCS=conversions.c ft_printf.c ft_printf_utils.c
OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
SRCS_BONUS=conversions_bonus.c conversions_checks_bonus.c \
			conversions_utils_bonus.c ft_printf_bonus.c \
			ft_printf_utils_bonus.c maths_utils_bonus.c
OBJS_BONUS=$(addprefix $(OBJS_DIR), $(SRCS_BONUS:.c=.o))
LIBFT_PATH=libs/libft_tools/
LIBFT=libs/libft_tools/libft_tools.a
NAME=libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@ar -rcs $@ $^
	@echo "Finished compiling ft_printf"

$(LIBFT):
	@make -sC $(LIBFT_PATH) all

bonus: $(OBJS_DIR).bonus

$(OBJS_DIR).bonus: $(OBJS_BONUS) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@ar -rcs $(NAME) $^
	@touch $(OBJS_DIR).bonus
	@echo "Finished compiling ft_printf bonuses"

$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -drf $(OBJS_DIR)
	@make -sC $(LIBFT_PATH) clean
	@echo "Cleaned ft_printf object files"

fclean: clean
	@rm -f $(NAME)
	@make -sC $(LIBFT_PATH) fclean
	@echo "Cleaned ft_printf"

re: fclean all
	@echo "Recompiled ft_printf"

.PHONY: all clean fclean re bonus
