/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:41:37 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/10 21:58:44 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_stack *stack_a, t_stack *stack_b, int range)
{
	t_node	*current;
	int		start;

	start = 0;
	while (stack_a->top)
	{
		current = stack_a->top;
		if (current->index < start)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			update_start_end(&start, &range, stack_a->size + stack_b->size);
		}
		else if (current->index <= range)
		{
			pb(stack_a, stack_b);
			update_start_end(&start, &range, stack_a->size + stack_b->size);
		}
		else
			ra(stack_a);
	}
}

static void	push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	index;

	while (stack_b->top)
	{
		index = max_index(stack_b);
		if (index <= stack_b->size / 2)
		{
			while (index-- > 0)
				rb(stack_b);
		}
		else
		{
			index = stack_b->size - index;
			while (index-- > 0)
				rrb(stack_b);
		}
		pa(stack_b, stack_a);
	}
}

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	int	range;

	range = get_range(stack_a->size);
	push_to_b(stack_a, stack_b, range);
	push_back_to_a(stack_a, stack_b);
}
