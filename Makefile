NAME = push_swap
RM = rm -f
CC = cc
MAKE = make --no-print-directory -C
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
INCLUDES = -Iincludes
SRC = $(addprefix src/, push_swap.c parse_input.c sort_small.c sort_small_utils.c \
				sort_large.c sort_in_array.c)\
	$(addprefix src/stack/, stack_utils.c normalize_stack.c swap_op.c push_op.c rotate_op.c reverse_rotate_op.c)
OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJ)
	@$(MAKE) ft_printf
	@$(CC) $(CFLAGS) $(OBJ) ./ft_printf/libftprintf.a -o $(NAME)

clean :
	@$(RM) $(OBJ)
	@$(MAKE) ft_printf clean

fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) ft_printf fclean

re : fclean all

.PHONY : all clean fclean re