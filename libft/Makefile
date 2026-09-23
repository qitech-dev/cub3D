SOURCES = ft_atoi.c ft_isascii.c ft_memcpy.c ft_strjoin.c ft_strnstr.c ft_bzero.c ft_isdigit.c ft_memmove.c ft_strlcat.c ft_strrchr.c ft_calloc.c ft_isprint.c ft_memset.c ft_strlcpy.c ft_substr.c ft_isalnum.c ft_memchr.c ft_strchr.c ft_strlen.c ft_tolower.c ft_isalpha.c ft_memcmp.c ft_strdup.c ft_strncmp.c ft_toupper.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c get_next_line_utils.c ft_printf.c ft_putnbr_len_fd.c ft_putchar_len_fd.c ft_putnbr_u_len.c ft_putendl_len_fd.c ft_putptr_len.c ft_putnbr_base_len.c ft_putstr_len_fd.c
CFLAGS += -Wall -Wextra -Werror
NAME = libft.a
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re