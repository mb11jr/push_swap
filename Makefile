NAME = push_swap
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes
SRC = src/push_swap/push_swap.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJ)
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ) ./ft_printf/libftprintf.a -o $(NAME)

clean :
	$(RM) $(OBJ)
	make clean -C ft_printf

fclean : clean
	$(RM) $(NAME)
	make fclean -C ft_printf

re : fclean all

.PHONY : all clean fclean re