SOURCE := main.c misc.c display.c error.c
OBJECT := $(SOURCE:%.c=%.o)
TARGET := ft_hexdump
CFLAGS := -Wall -Wextra -Werror

$(TARGET): $(OBJECT)
	cc -o $@ $^

%.o: %.c
	cc $(CFLAGS) -c -o $@ $^

all: $(TARGET)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(TARGET)

re: fclean all
