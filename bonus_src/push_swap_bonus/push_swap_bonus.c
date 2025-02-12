/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:54:43 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/12 13:42:23 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_instruction(t_stack *stack_a, t_stack *stack_b, int i)
{
	if (i == 0)
		pa(stack_b, stack_a);
	if (i == 1)
		pb(stack_a, stack_b);
	if (i == 2)
		sa(stack_a);
	if (i == 3)
		sb(stack_b);
	if (i == 4)
		ss(stack_a, stack_b);
	if (i == 5)
		ra(stack_a);
	if (i == 6)
		rb(stack_b);
	if (i == 7)
		rr(stack_a, stack_b);
	if (i == 8)
		rra(stack_a);
	if (i == 9)
		rrb(stack_b);
	if (i == 10)
		rrr(stack_a, stack_b);
}

int    valid_instruction(char *action, t_stack *stack_a, t_stack *stack_b)
{
    unsigned int i;
    const char *actions[] = {"pa", "pb", "sa", "sb", "ss", "ra", "rb", "rr", "rra", "rrb", "rrr"};

    i = 0;
    while (i <= 10)
    {
        if (ft_strncmp(action, actions[i], 2) == 0)
		{
			exec_instruction(stack_a, stack_b, i);
            return 1;
		}
        i++;
    }
    return 0;
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	ft_printf("printing sorted stack:\n");
	current = stack->top;
	while (current)
	{
		ft_printf("%d >> ", current->value);
		current = current->next;
	}
	ft_printf("NULL");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char *action;

	if (ac < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	parse_input(ac, av, stack_a);
	action = get_next_line(0);
	while (action)
	{
		if (!valid_instruction(action, stack_a, stack_b))
		{
			free_stack(stack_b);
			ft_exit(stack_a);
		}
		free(action);
		action = get_next_line(0);
	}
	print_stack(stack_a);
	if (is_sorted(stack_a) && !stack_b->top)
	{
		ft_printf("OK\n");
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	else
	{
		ft_printf("KO\n");
		free_stack(stack_a);
		free_stack(stack_b);
		return (1);
	}
	return (0);
}
