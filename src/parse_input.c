/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:36:37 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/05 12:02:20 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_duplicate(t_stack *stack, int num)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == num)
			return (1);
		current = current->next;
	}
	return (0);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_free(t_stack *stack, char **split_arg)
{
	ft_printf("Error\n");
	free_stack(stack);
	free_split(split_arg);
	exit(1);
}

static void	valid_arguments(t_stack *stack, char **split_arg)
{
	int		j;
	long	num;

	j = 0;
	while (split_arg[j])
	{
		if (!is_digit(split_arg[j]))
			ft_free(stack, split_arg);
		num = ft_atol(split_arg[j]);
		if (num < INT_MIN || num > INT_MAX || is_duplicate(stack, num))
			ft_free(stack, split_arg);
		push_node(stack, num);
		j++;
	}
}

void	parse_input(int ac, char **av, t_stack *stack)
{
	int		i;
	char	**split_arg;

	i = 1;
	while (i < ac)
	{
		split_arg = ft_split(av[i], ' ');
		if (!split_arg)
		{
			ft_printf("Error\n");
			free_stack(stack);
			exit(1);
		}
		valid_arguments(stack, split_arg);
		free_split(split_arg);
		i++;
	}
}
