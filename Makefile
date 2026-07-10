CC       = cc
CFLAGS   = -Wall -Wextra -Werror
TARGET   = a.out
SRCS     = $(wildcard *.c)
OBJS     = $(SRCS:.c=.o)
.PHONY: all clean run fclean
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: all
	./$(TARGET)

fclean: clean
	$(RM) $(NAME)
