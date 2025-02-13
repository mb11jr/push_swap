/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:29:32 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/13 12:58:03 by mbentale         ###   ########.fr       */
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

void	ft_checker(t_stack *a, t_stack *b, char *str, int status)
{
	ft_printf("%s\n", str);
	free_stack(a);
	free_stack(b);
	exit(status);
}

static void	exec_instruction(t_stack *stack_a, t_stack *stack_b, int i)
{
	if (i == 0)
		pa(stack_b, stack_a);
	else if (i == 1)
		pb(stack_a, stack_b);
	else if (i == 2)
		sa(stack_a);
	else if (i == 3)
		sb(stack_b);
	else if (i == 4)
		ss(stack_a, stack_b);
	else if (i == 5)
		ra(stack_a);
	else if (i == 6)
		rb(stack_b);
	else if (i == 7)
		rr(stack_a, stack_b);
	else if (i == 8)
		rra(stack_a);
	else if (i == 9)
		rrb(stack_b);
	else if (i == 10)
		rrr(stack_a, stack_b);
}

int	valid_instruction(char *action, t_stack *stack_a, t_stack *stack_b)
{
	int				i;
	const char		*arr[] = {"pa\n", "pb\n", "sa\n", "sb\n", "ss\n", "ra\n",
		"rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};

	i = 0;
	while (i <= 10)
	{
		if (ft_strncmp(action, arr[i], ft_strlen(arr[i])) == 0)
		{
			exec_instruction(stack_a, stack_b, i);
			return (1);
		}
		i++;
	}
	return (0);
}
