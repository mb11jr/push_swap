NAME = push_swap
BONUS = checker
RM = rm -f
CC = cc
MAKEFLAGS += --no-print-directory
MAKE = make -C
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
INCLUDES = -Iincludes
SRC = $(addprefix src/push_swap_src/, push_swap.c parse_input.c free.c sort_small.c sort_large.c sort_utils.c sort_in_array.c)\
	$(addprefix src/stack/, stack_utils.c swap_op.c push_op.c rotate_op.c reverse_rotate_op.c)
OBJ = $(SRC:.c=.o)
BONUS_SRC = $(addprefix bonus_src/push_swap_bonus/, push_swap_bonus.c utils_bonus.c free_bonus.c parse_input_bonus.c)\
			$(addprefix bonus_src/stack_bonus/, push_op_bonus.c reverse_rotate_op_bonus.c rotate_op_bonus.c stack_utils_bonus.c swap_op_bonus.c)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJ)
	@echo "Compiling source files...⏳"
	@echo "Done ✅"
	@echo "Compiling ft_printf, and libft source files...⏳"
	@$(MAKE) ft_printf
	@echo "Done ✅"
	@echo "Linking...⏳"
	@echo "Done ✅"
	@$(CC) $(CFLAGS) $(OBJ) ./ft_printf/libftprintf.a -o $(NAME)
	@echo "Your program [ $(NAME) ] is ready!"

bonus : $(BONUS)

$(BONUS) : $(BONUS_OBJ)
	@echo "Compiling bonus files...⏳"
	@echo "Done ✅"
	@echo "Compiling ft_printf, libft, and GNL source files...⏳"
	@$(MAKE) ft_printf
	@$(MAKE) gnl
	@echo "Done ✅"
	@echo "Linking...⏳"
	@echo "Done ✅"
	@$(CC) $(CFLAGS) $(BONUS_OBJ) ./gnl/gnl.a ./ft_printf/libftprintf.a -o $(BONUS)
	@echo "Your program [ $(BONUS) ] is ready!"

clean :
	@echo "Cleaning object files...🚮"
	@$(RM) $(OBJ) $(BONUS_OBJ)
	@$(MAKE) ft_printf clean
	@$(MAKE) gnl clean
	@echo "Done ✅"

fclean : clean
	@echo "Full clean begins... 🚮"
	@$(RM) $(NAME) $(BONUS)
	@$(MAKE) ft_printf fclean
	@$(MAKE) gnl fclean
	@echo "Full clean is done ✅"

re : fclean all

.PHONY : all clean fclean re bonus