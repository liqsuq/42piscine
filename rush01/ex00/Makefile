rush-01: main.o misc.o calc.o check.o
	cc -Wall -Wextra -Werror -o $@ $^

main.o: main.c
	cc -Wall -Wextra -Werror -c $^

misc.o: misc.c
	cc -Wall -Wextra -Werror -c $^

calc.o: calc.c
	cc -Wall -Wextra -Werror -c $^

check.o: check.c
	cc -Wall -Wextra -Werror -c $^

all: rush-01

clean:
	rm -f main.o misc.o calc.o check.o

fclean: clean
	rm -f rush-01

re: fclean
	make all
