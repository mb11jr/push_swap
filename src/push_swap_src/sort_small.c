/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:53:24 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/13 11:43:55 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->top->value > stack->bottom->value)
		sa(stack);
}

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->top->value;
	b = stack->top->next->value;
	c = stack->bottom->value;
	if (a > b && b < c && c > a)
		sa(stack);
	else if (a > b && b > c && c < a)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && c < a)
		ra(stack);
	else if (a < b && b > c && c > a)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && c < a)
		rra(stack);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	push_smallest(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_b, stack_a);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	push_smallest(stack_a, stack_b);
	push_smallest(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}
