SRCDIR := srcs
INCDIR := includes
OBJECT := srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_strcmp.o srcs/ft_strlen.o srcs/ft_swap.o
BINARY := libft.a
CFLAGS := -Wall -Wextra -Werror -I$(INCDIR)

$(BINARY): $(OBJECT)
	ar rsv $@ $^

all: libft.a

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(BINARY)

re: fclean all
