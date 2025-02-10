/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:34:06 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/08 15:28:12 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size < 2)
		return (1);
	current = stack->top;
	while (current)
	{
		if (current->next && current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

static void	move_to_top(t_stack *stack, int pos)
{
	if (pos <= stack->size / 2)
	{
		while (pos > 0)
		{
			rotate(stack);
			pos--;
		}
	}
	else
	{
		pos = stack->size - pos;
		while (pos > 0)
		{
			reverse_rotate(stack);
			pos--;
		}
	}
}

void	push_smallest(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	int		smallest;
	int		pos;
	int		i;

	if (!a || a->size < 2)
		return ;
	pos = 0;
	i = 0;
	tmp = a->top;
	smallest = tmp->value;
	while (tmp)
	{
		if (tmp->value < smallest)
		{
			smallest = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	move_to_top(a, pos);
	push(a, b);
}
