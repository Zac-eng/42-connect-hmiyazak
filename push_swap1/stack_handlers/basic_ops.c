/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:37:03 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/06 19:25:51 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_top(t_stack *stack, int new_element)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node *) * 1);
	if (new_node == NULL)
		exit(1);
	new_node->previous = NULL;
	new_node->body = new_element;
	new_node->next = stack->top;
	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		stack->top->next = new_node;
		new_node->previous = stack->top;
		stack->top = new_node;
	}
	stack->current_size += 1;
}

void	push_bottom(t_stack *stack, int new_element)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node *) * 1);
	if (new_node == NULL)
		exit(1);
	new_node->previous = stack->bottom;
	new_node->body = new_element;
	new_node->next = NULL;
	if (stack->bottom != NULL)
		stack->bottom->next = new_node;
	stack->bottom = new_node;
	if (stack->current_size == 0)
		stack->top = new_node;
	stack->current_size += 1;
}

int	pop_top(t_stack *stack)
{
	t_node	*poped_node;
	int		poped_element;

	poped_node = stack->top;
	poped_element = poped_node->body;
	stack->top = poped_node->next;
	if (stack->current_size == 1)
		stack->bottom = NULL;
	if (stack->top != NULL)
		stack->top->previous = NULL;
	stack->current_size -= 1;
	free(poped_node);
	return (poped_element);
}

int	pop_bottom(t_stack *stack)
{
	t_node	*poped_node;
	int		poped_element;

	poped_node = stack->bottom;
	poped_element = poped_node->body;
	stack->bottom = poped_node->previous;
	if (stack->current_size == 1)
		stack->top = NULL;
	if (stack->bottom != NULL)
		stack->bottom->next = NULL;
	stack->current_size -= 1;
	free(poped_node);
	return (poped_element);
}
