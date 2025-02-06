/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:07:22 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/05 09:19:51 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_stack_to_array(t_stack *stack)
{
	int		*arr;
	t_node	*tmp;
	int		i;

	arr = malloc(stack->size * sizeof(int));
	if (!arr)
		return (NULL);
	tmp = stack->top;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	get_rank(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i + 1);
		i++;
	}
	return (-1);
}

void	normalize_stack(t_stack *stack)
{
	int		*arr;
	t_node	*tmp;

	arr = copy_stack_to_array(stack);
	if (!arr)
		return ;
	sort_array(arr, stack->size);
	tmp = stack->top;
	while (tmp)
	{
		tmp->value = get_rank(arr, stack->size, tmp->value);
		tmp = tmp->next;
	}
	free(arr);
}
