NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = push_swap.h

SRCS = main.c \
    array_functions_00.c \
    array_functions_01.c \
    array_functions_02.c \
    bench_functions.c \
    bench_printing_functions.c \
    char_functions.c \
    ft_printf_chars_printer.c \
    ft_printf_digits_printer.c \
    ft_printf_hex_printer.c \
    ft_printf.c \
    ft_split.c \
    input_handling_functions_00.c \
    input_handling_functions_01.c \
    math_functions.c \
    router.c \
    sort_alg_bucket_functions_00.c \
    sort_alg_bucket_functions_01.c \
    sort_alg_minmax_functions.c \
    sort_alg_radix_functions.c \
    stack_adv_manip_functions.c \
    stack_key_manip_functions.c \
    stack_low_manip_functions_00.c \
    stack_low_manip_functions_01.c \
    string_functions_00.c \
    string_functions_01.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
