CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_tolower.c ft_toupper.c ft_strchr.c
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
