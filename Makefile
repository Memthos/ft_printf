CC=gcc
INCLUDES=includes/
CFLAGS=-Werror -Wall -Wextra -I $(INCLUDES)

SRCS_DIR=srcs/
OBJS_DIR=objs/

SRCS=conversions.c ft_printf.c ft_printf_utils.c
OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

SRCS_BONUS=conversions_bonus.c conversions_checks_bonus.c \
		conversions_utils_bonus.c ft_printf_bonus.c \
		ft_printf_utils_bonus.c maths_utils_bonus.c
OBJS_BONUS=$(addprefix $(OBJS_DIR), $(SRCS_BONUS:.c=.o))

UTILS=ft_bzero.c ft_calloc.c ft_isdigit.c ft_memset.c ft_strdup.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strncpy.c
OBJS_UTILS=$(addprefix $(OBJS_DIR), $(UTILS:.c=.o))

NAME=libftprintf.a

all: $(OBJS_DIR).manda

$(OBJS_DIR).manda: $(OBJS) $(OBJS_UTILS)
	@rm -f $(NAME) $(OBJS_DIR).bonus
	@ar -rcs $(NAME) $^
	@touch $(OBJS_DIR).manda
	@echo "Finished compiling ft_printf"

bonus: $(OBJS_DIR).bonus

$(OBJS_DIR).bonus: $(OBJS_BONUS) $(OBJS_UTILS)
	@rm -f $(NAME) $(OBJS_DIR).manda
	@ar -rcs $(NAME) $^
	@touch $(OBJS_DIR).bonus
	@echo "Finished compiling ft_printf bonuses"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
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
