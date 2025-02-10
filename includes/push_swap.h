/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:52:13 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/10 21:58:05 by mbentale         ###   ########.fr       */
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
void				free_stack(t_stack *stack);
void				free_split(char **split);
void				ft_exit(t_stack *stack);
void				ft_free(t_stack *stack, char **split_arg);
t_node				*create_node(int value);
t_stack				*init_stack(void);
void				push_node(t_stack *stack, int value);
long				ft_atol(const char *str);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				pa(t_stack *stack_b, t_stack *stack_a);
void				pb(t_stack *stack_a, t_stack *stack_b);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);
int					is_sorted(t_stack *stack);
void				sort_two(t_stack *stack);
void				sort_three(t_stack *stack);
void				sort_four(t_stack *stack_a, t_stack *stack_b);
void				sort_five(t_stack *stack_a, t_stack *stack_b);
void				sort_large(t_stack *stack_a, t_stack *stack_b);
void				push_smallest(t_stack *a, t_stack *b);
int					*clone_stack(t_stack *stack);
void				quick_sort(int *arr, int start, int end);
void				get_index(t_stack *stack, int *arr);
int					max_index(t_stack *stack);
void				update_start_end(int *start, int *end, int size);
int					get_range(int size);
#endif