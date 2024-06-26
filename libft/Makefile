CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
OBJECTS = ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_memcpy.o ft_memmove.o ft_memset.o ft_strlcpy.o ft_strlen.o ft_tolower.o ft_toupper.o ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_atoi.o ft_itoa.o
OBJECTS_BONUS = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o

all : $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $<

$(NAME) : $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJECTS_BONUS)
	ar -rcs $(NAME) $(OBJECTS_BONUS)

.PHONY : clean fclean re bonus