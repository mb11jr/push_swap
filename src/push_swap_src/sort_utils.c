/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:29:32 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/10 21:59:58 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	max_index(t_stack *stack)
{
	t_node	*tmp;
	int		max;
	int		max_index;
	int		i;

	tmp = stack->top;
	max = tmp->value;
	max_index = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			max_index = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (max_index);
}

void	update_start_end(int *start, int *end, int size)
{
	if (*start <= (*end) - 1)
		(*start)++;
	if (*end <= size - 1)
		(*end)++;
}

int	get_range(int size)
{
	if (size <= 100)
		return (size / 5);
	return (size / 13);
}
