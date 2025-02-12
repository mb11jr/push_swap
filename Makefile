NAME = push_swap
BONUS = checker
RM = rm -f
CC = cc
MAKE = make --no-print-directory -C
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
INCLUDES = -Iincludes
SRC = $(addprefix src/push_swap_src/, push_swap.c parse_input.c free.c sort_small.c sort_large.c sort_utils.c sort_in_array.c)\
	$(addprefix src/stack/, stack_utils.c swap_op.c push_op.c rotate_op.c reverse_rotate_op.c)
OBJ = $(SRC:.c=.o)
BONUS_SRC = $(addprefix bonus_src/push_swap_bonus/, push_swap_bonus.c utils_bonus.c free_bonus.c parse_input_bonus.c)\
			$(addprefix bonus_src/stack/, push_op_bonus.c reverse_rotate_op_bonus.c rotate_op_bonus.c stack_utils_bonus.c swap_op_bonus.c)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJ)
	@$(MAKE) ft_printf
	@$(CC) $(CFLAGS) $(OBJ) ./ft_printf/libftprintf.a -o $(NAME)

bonus : $(BONUS_OBJ)
	$(MAKE) ft_printf
	$(MAKE) gnl
	@$(CC) $(CFLAGS) $(BONUS_OBJ) ./gnl/gnl.a ./ft_printf/libftprintf.a -o $(BONUS)

clean :
	@$(RM) $(OBJ) $(BONUS_OBJ)
	@$(MAKE) ft_printf clean
	@$(MAKE) gnl clean

fclean : clean
	@$(RM) $(NAME) $(BONUS)
	@$(MAKE) ft_printf fclean
	@$(MAKE) gnl fclean

re : fclean all

.PHONY : all clean fclean re