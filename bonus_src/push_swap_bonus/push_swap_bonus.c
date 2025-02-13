/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:54:43 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/13 10:59:40 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*action;
	
	if (ac < 2)
		return (0);
	stack_a = init_stack();
	parse_input(ac, av, stack_a);
	stack_b = init_stack();
	action = get_next_line(0);
	while (action)
	{
		if (!valid_instruction(action, stack_a, stack_b))
		{
			free(action);
			free_stack(stack_b);
			get_next_line(-1);
			ft_exit(stack_a);
		}
		free(action);
		action = get_next_line(0);
	}
	if (is_sorted(stack_a) && !stack_b->top)
		ft_checker(stack_a, stack_b, "OK", 0);
	ft_checker(stack_a, stack_b, "KO", 1);
}
