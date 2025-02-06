NAME = push_swap
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
INCLUDES = -Iincludes
SRC = $(addprefix src/push_swap/, push_swap.c parse_input.c sort_small.c sort_small_utils.c)\
	$(addprefix src/stack/, stack_utils.c normalize_stack.c swap_op.c push_op.c rotate_op.c reverse_rotate_op.c)
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