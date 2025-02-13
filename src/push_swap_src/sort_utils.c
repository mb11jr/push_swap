/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:29:32 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/13 11:43:41 by mbentale         ###   ########.fr       */
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

static void	move_to_top(t_stack *stack, int pos)
{
	if (pos <= stack->size / 2)
	{
		while (pos > 0)
		{
			ra(stack);
			pos--;
		}
	}
	else
	{
		pos = stack->size - pos;
		while (pos > 0)
		{
			rra(stack);
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
	pb(a, b);
}
