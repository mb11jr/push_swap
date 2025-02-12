/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:25:34 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/12 13:26:05 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return ;
	node = stack->bottom;
	stack->bottom = node->prev;
	stack->bottom->next = NULL;
	node->next = stack->top;
	node->prev = NULL;
	stack->top->prev = node;
	stack->top = node;
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
