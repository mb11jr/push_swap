NAME = gnl.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re