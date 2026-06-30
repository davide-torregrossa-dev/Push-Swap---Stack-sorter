NAME        = libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I.
RM          = rm -f

LIBFT_DIR   = libft/
PRINTF_DIR  = ft_printf/

LIBFT_SRC   = ft_atoi.c ft_atol.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
              ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c \
              ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
              ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memchr.c \
              ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
              ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
              ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
              ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
              ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
LIBFT_SRCS  = $(addprefix $(LIBFT_DIR), $(LIBFT_SRC))

PRINTF_SRC  = ft_print_c.c ft_print_d.c ft_print_ptr.c ft_print_s.c \
              ft_print_u.c ft_print_x.c ft_print_x_up.c ft_printf.c
PRINTF_SRCS = $(addprefix $(PRINTF_DIR), $(PRINTF_SRC))

SRCS        = $(LIBFT_SRCS) $(PRINTF_SRCS)
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
