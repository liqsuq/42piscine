SOURCE := main.c dict.c lookup.c misc.c read_dict.c trim_space_between_words.c
OBJECT := $(SOURCE:%.c=%.o)
TARGET := rush-02
CFLAGS := -Wall -Wextra -Werror

.PHONY: all clean fclean re

$(TARGET): $(OBJECT)
	cc -o $@ $^

%.o: %.c
	cc $(CFLAGS) -c $^

all: $(TARGET)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(TARGET)

re: fclean all
