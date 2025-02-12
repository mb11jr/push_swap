/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:36:37 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/12 09:51:00 by mbentale         ###   ########.fr       */
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

static void	valid_arguments(t_stack *stack, char **split_arg)
{
	long	num;
	int		j;

	j = 0;
	while (split_arg[j])
	{
		num = ft_atol(stack, split_arg, split_arg[j]);
		if (!is_digit(split_arg[j]) || is_duplicate(stack, num))
			ft_free(stack, split_arg);
		push_node(stack, num);
		j++;
	}
}

void	parse_input(int ac, char **av, t_stack *stack)
{
	char	**split_arg;
	char	*arg;
	int		i;

	i = 1;
	while (i < ac)
	{
		arg = ft_strtrim(av[i], " ");
		if (arg[0] == '\0')
		{
			free(arg);
			ft_exit(stack);
		}
		split_arg = ft_split(arg, ' ');
		if (!split_arg)
			ft_exit(stack);
		free(arg);
		valid_arguments(stack, split_arg);
		free_split(split_arg);
		i++;
	}
}
