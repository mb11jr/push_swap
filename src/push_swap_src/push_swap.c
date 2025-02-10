/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:54:43 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/10 22:03:33 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
	else
		sort_large(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*arr;

	if (ac < 2)
		return (0);
	stack_a = init_stack();
	parse_input(ac, av, stack_a);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		return (0);
	}
	arr = clone_stack(stack_a);
	quick_sort(arr, 0, stack_a->size - 1);
	get_index(stack_a, arr);
	stack_b = init_stack();
	ft_sort(stack_a, stack_b);
	// print_stack(stack_a);
	free(arr);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
