/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:54:43 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/04 12:27:38 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	value;

	sign = 1;
	value = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		value = value * 10 + str[i] - 48;
        // if (value < INT_MIN)
        //     return -1;
        // if (value > INT_MAX)
        //     return 0;
		// // if (value < 0)
		// // 	return (-sign * (sign == 1));
        if (value > INT_MAX)
		{
			if (sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		i++;
	}
	return (value * sign);
}

t_node *create_node(int value)
{
    t_node *new;

    new = malloc(sizeof(t_node));
    if (!new)
        return NULL;
    new->value = value;
    new->index = -1;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

t_stack *create_stack(void)
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return NULL;
    stack->top = NULL;    
    stack->bottom = NULL;
    stack->size = 0;
    return stack;
}

void push(t_stack *stack, int value)
{
    t_node *new_node;

    new_node = create_node(value);
    if (!new_node)
        return ;
    if (!stack->top)
    {
        stack->top = new_node;
        stack->bottom = new_node;
    }
    else
    {
        new_node->next = stack->top;
        stack->top->prev = new_node;
        stack->top = new_node;
    }
    stack->size++;
}

int is_digit(char *str)
{
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
		return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}

int is_duplicate(t_stack *stack, int num)
{
    t_node *current;

    current = stack->top;
    while (current)
    {
        if (current->value == num)
            return 1;
        current = current->next;
    }
    return 0;
}
void    parse_input(int ac, char **av, t_stack *stack)
{
    int i = 1;
    long num;

    while (i < ac)
    {
        if(!is_digit(av[i]))
        {
            ft_printf("Error\n");
            exit(1);
        }
        num = ft_atol(av[i]);
        // ft_printf("test: %d\n", num);
        if (num < INT_MIN || num > INT_MAX || is_duplicate(stack, num))
        {
            ft_printf("Error\n");
            exit(1);
        }
        push(stack, num);
        i++;
    }
}
int main(int ac, char **av)
{
    t_stack *stack_a;
    t_node *current;
    
    if (ac < 2)
        return 1;
    stack_a = create_stack();
    parse_input(ac, av, stack_a);
    // display the stack
    current = stack_a->top;
    while (current)
    {
        ft_printf("%d\n", current->value);
        current = current->next;
    }
    return 0;
}
