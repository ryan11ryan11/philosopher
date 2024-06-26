CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT = client
COMMON = main
NAME = philo

#COMOBJ = $(addprefix $(COMDIR)/, $(addsuffix .o, $(COMMON)))
OBJ = $(addsuffix .o, $(COMMON))
AR = ar -rcs

all : $(NAME)

# -I means that headerfile is located at current directory
%.o : %.c philosopher.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME) : $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ) ./libft/libft.a -o $(NAME) -lpthread


# Make lib
# @ : target
# < : first dependency
# -L : lib file is located at current DIR
clean:
	rm -f $(OBJ)
	$(MAKE) -C ./libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

libclean :
	$(MAKE) -C $(LIBDIR)/ clean

libfclean :
	$(MAKE) -C $(LIBDIR)/ fclean

.PHONY : all clean fclean re