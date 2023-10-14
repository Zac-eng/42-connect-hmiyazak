/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afew_nodes_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:14:29 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/14 19:06:34 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smallest_nodes_operation(t_stack *stack)
{
	if (stack == NULL)
		exit(1);
	if (stack->top->body == 3)
		ra(stack);
	if (stack->top->body == 2)
	{
		if (stack->top->previous->body == 1)
			return (sa(stack));
		else
			return (rra(stack));
	}
	if (stack->top->previous->body == 2)
		return ;
	else
	{
		sa(stack);
		ra(stack);
		return ;
	}
}

void	four_nodes_operation(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		exit(1);
	while (stack_a->top->body != 4)
		ra(stack_a);
	pb(stack_a, stack_b);
	smallest_nodes_operation(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
	return ;
}

void	five_nodes_operation(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		exit(1);
	while (stack_a->top->body != 4 && stack_a->top->body != 5)
		ra(stack_a);
	pb(stack_a, stack_b);
	while (stack_a->top->body != 4 && stack_a->top->body != 5)
		ra(stack_a);
	pb(stack_a, stack_b);
	smallest_nodes_operation(stack_a);
	if (stack_b->top->body == 5)
		sb(stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
	return ;
}
