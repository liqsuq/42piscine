SOURCE := ft_display_file.c
OBJECT := $(SOURCE:%.c=%.o)
BINARY := ft_display_file
CFLAGS := -Wall -Wextra -Werror

$(BINARY): $(OBJECT)
	cc -o $@ $^

%.o: %.c
	cc $(CFLAGS) -c -o $@ $^

all: $(BINARY)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(BINARY)

re: fclean all
