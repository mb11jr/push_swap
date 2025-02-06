/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:52:13 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/06 18:36:19 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/include/ft_printf.h"
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

void				parse_input(int ac, char **av, t_stack *stack);
t_node				*create_node(int value);
t_stack				*init_stack(void);
void				free_stack(t_stack *stack);
void				push_node(t_stack *stack, int value);
long				ft_atol(const char *str);
void				normalize_stack(t_stack *stack);
void    swap(t_stack *stack);
void    push(t_stack *src, t_stack *dst);
void    pa(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_a, t_stack *stack_b);
void    rotate(t_stack *stack);
void    ra(t_stack *stack_a);
void    rb(t_stack *stack_b);
void    reverse_rotate(t_stack *stack);
int		is_sorted(t_stack *stack);
void    push_smallest(t_stack *a, t_stack *b);
void    sort_two(t_stack *stack);
void    sort_three(t_stack *stack);
void    sort_four(t_stack *stack_a, t_stack *stack_b);
void    sort_five(t_stack *stack_a, t_stack *stack_b);

#endif