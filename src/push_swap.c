/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:54:43 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/10 16:43:54 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort_two(stack_a);
	if (stack_a->size == 3)
		sort_three(stack_a);
	if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	// t_node	*current;
	int		*arr;
	// int		i = 0;

	if (ac < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	parse_input(ac, av, stack_a);
	if (is_sorted(stack_a))
		return (0);
	sort_small(stack_a, stack_b);
	stack_b = init_stack();
	arr = clone_stack(stack_a);
	quick_sort(arr, 0, stack_a->size - 1);
	get_index(stack_a, arr);
	if (stack_a->size > 5)
		sort_large(stack_a, stack_b);
	// ft_printf("printing sorted stack:\n");
	// current = stack_a->top;
	// while(current)
	// {
	// 	ft_printf("%d--->", current->value);
	// 	current = current->next;
	// }
	// ft_printf("NULL");
	free(arr);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
