/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:54:43 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/13 11:44:16 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	free(arr);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
