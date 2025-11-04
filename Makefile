CC=cc
CFLAGS=-Werror -Wall -Wextra
SOURCES=ft_printf.c ft_output_maths.c ft_output_str.c
OBJECTS=$(SOURCES:.c=.o)
NAME=libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re