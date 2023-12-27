CC = gcc
CFLAGS = -Wall -Wextra -Werror

STRING_FUNCS = ft_strlen.c ft_strchr.c ft_toupper.c ft_tolower.c ft_strlcpy.c ft_strlcat.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_substr.c ft_strdup.c ft_strjoin.c ft_strtrim.c ft_split.c
NUM_FUNCS = ft_isdigit.c ft_atoi.c
CHAR_FUNCS = ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memchr.c
MEMORY_FUNCS = ft_bzero.c ft_memcpy.c ft_memset.c ft_memmove.c ft_memcmp.c ft_calloc.c
FILE_FUNCS = ft_putchar_fd.c

SOURCES = $(STRING_FUNCS) $(NUM_FUNCS) $(CHAR_FUNCS) $(MEMORY_FUNCS) $(FILE_FUNCS_FUNCS)

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
