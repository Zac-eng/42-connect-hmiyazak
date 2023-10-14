/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_five_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:14:29 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/14 13:35:43 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_nodes_operation(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top->body == 3)
		ra(stack_a);
	if (stack_a->top->body == 2)
	{
		if (stack_a->top->previous->body == 1)
			return (sa(stack_a));
		else
			return (rra(stack_a));
	}
	if (stack_a->bottom->body == 3)
		return ;
	if (stack_a->top->previous->body == stack_a->bottom->body)
		return ;
	else
	{
		pb(stack_a, stack_b);
		sa(stack_a);
		pa(stack_a, stack_b);
		return ;
	}
}

// void	five_nodes_operation(t_stack *stack_a, t_stack *stack_b)
// {
	
// }
