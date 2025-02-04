/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:52:13 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/04 17:46:38 by mbentale         ###   ########.fr       */
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

int		is_digit(char *str);
int		is_duplicate(t_stack *stack, int num);
void	free_split(char **split);
void	valid_arguments(t_stack *stack, char **split_arg);
void	parse_input(int ac, char **av, t_stack *stack);
t_node	*create_node(int value);
t_stack	*init_stack(void);
void	push(t_stack *stack, int value);
long	ft_atol(const char *str);
void	normalize_stack(t_stack *stack);

#endif