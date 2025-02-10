/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:53:24 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/06 18:35:04 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->top->value > stack->bottom->value)
		swap(stack);
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
		swap(stack);
	else if (a > b && b > c && c < a)
	{
		swap(stack);
		reverse_rotate(stack);
	}
	else if (a > b && b < c && c < a)
		rotate(stack);
	else if (a < b && b > c && c > a)
	{
		swap(stack);
		rotate(stack);
	}
	else if (a < b && b > c && c < a)
		reverse_rotate(stack);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	push_smallest(stack_a, stack_b);
	sort_three(stack_a);
	push(stack_b, stack_a);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	push_smallest(stack_a, stack_b);
	push_smallest(stack_a, stack_b);
	sort_three(stack_a);
	push(stack_b, stack_a);
	push(stack_b, stack_a);
}
