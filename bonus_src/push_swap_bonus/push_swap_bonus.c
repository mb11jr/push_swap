/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:54:43 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/12 22:33:52 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_instruction(t_stack *stack_a, t_stack *stack_b, int i)
{
	if (i == 0)
		pa(stack_b, stack_a);
	if (i == 1)
		pb(stack_a, stack_b);
	if (i == 2)
		sa(stack_a);
	if (i == 3)
		sb(stack_b);
	if (i == 4)
		ss(stack_a, stack_b);
	if (i == 5)
		ra(stack_a);
	if (i == 6)
		rb(stack_b);
	if (i == 7)
		rr(stack_a, stack_b);
	if (i == 8)
		rra(stack_a);
	if (i == 9)
		rrb(stack_b);
	if (i == 10)
		rrr(stack_a, stack_b);
}

int	valid_instruction(char *action, t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	i;
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

void	print_stack(t_stack *stack)
{
	t_node	*current;

	ft_printf("printing sorted stack:\n");
	current = stack->top;
	while (current)
	{
		ft_printf("%d >> ", current->value);
		current = current->next;
	}
	ft_printf("NULL");
}

void	ft_checker(t_stack *a, t_stack *b, char *str, int status)
{
	ft_printf("%s\n", str);
	free_stack(a);
	free_stack(b);
	exit(status);
}

int	main(int ac, char **av)
{
	char	*action;

	t_stack(*stack_a), (*stack_b);
	if (ac < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	parse_input(ac, av, stack_a);
	action = get_next_line(0);
	while (action)
	{
		if (!valid_instruction(action, stack_a, stack_b))
		{
			free(action);
			free_stack(stack_b);
			ft_exit(stack_a);
		}
		free(action);
		action = get_next_line(0);
	}
	free(action);
	if (is_sorted(stack_a) && !stack_b->top)
		ft_checker(stack_a, stack_b, "OK", 0);
	ft_checker(stack_a, stack_b, "KO", 1);
}
