SOURCE := ft_cat.c
OBJECT := $(SOURCE:%.c=%.o)
BINARY := ft_cat
CFLAGS := -Wall -Wextra -Werror

$(BINARY): $(OBJECT)
	cc -o  $@ $^

%.o: %.c
	cc $(CFLAGS) -c -o $@ $^

all: $(BINARY)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(BINARY)

re: fclean all
