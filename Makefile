CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_isalpha.c ft_isdigit.c isalnum.c
NAME = libft.a

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
ifeq ($(OS),Windows_NT)
	del $(OBJECTS)
else
	rm -rf $(OBJECTS)
endif

fclean: clean
ifeq ($(OS),Windows_NT)
	del $(NAME)
else
	rm -f $(NAME)
endif

re: fclean all
