SOURCE := main.c misc.c map.c read_map.c solve_map.c show_map.c
OBJECT := $(SOURCE:%.c=%.o)
TARGET := bsq
CFLAGS := -Wall -Wextra -Werror

$(TARGET): $(OBJECT)
	cc -o $@ $^

all: $(TARGET)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(TARGET)

re: fclean all
