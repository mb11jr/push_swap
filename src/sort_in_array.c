/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:38:47 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/09 10:26:19 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*clone_stack(t_stack *stack)
{
	t_node	*node;
	int		*arr;
	int		i;

	arr = malloc(stack->size * sizeof(int));
	node = stack->top;
	i = 0;
	while (node)
	{
		arr[i++] = node->value;
		node = node->next;
	}
	return (arr);
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int *arr, int start, int end)
{
	int	i;
	int	j;
	int	pivot;

	pivot = arr[end];
	i = start - 1;
	j = start;
	while (j <= end - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[j]);
	return (i + 1);
}

void	quick_sort(int *arr, int start, int end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = partition(arr, start, end);
		quick_sort(arr, start, pivot_index - 1);
		quick_sort(arr, pivot_index + 1, end);
	}
}

void    get_index(t_stack *stack, int *arr)
{
    t_node *current;
    int i;

    current = stack->top;
    while(current)
    {
        i = 0;
        while (i <= stack->size - 1)
        {
            if (current->value == arr[i])
            {
                current->index = i;
                break;
            }
            i++;
        }
        current = current->next;
    }
}
