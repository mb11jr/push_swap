/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:54:43 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/04 16:02:56 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_node	*current;

	if (ac < 2)
		return (1);
	stack_a = create_stack();
	parse_input(ac, av, stack_a);
	// display the stack
	current = stack_a->top;
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
	return (0);
}
