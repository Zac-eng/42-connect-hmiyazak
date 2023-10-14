/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_nodes_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:58:44 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/14 23:08:27 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_lump_top(int max, t_stack *stack_a, t_stack *stack_b);
static void	push_lump_bottom(int max, t_stack *stack_a, t_stack *stack_b);
static void	sort_and_return(int *range, t_stack *stack_a, t_stack *stack_b);
static void	pa_and_proceed(int *next, t_stack *stack_a, t_stack *stack_b);

void	many_nodes_operation(int node_num, t_stack *stack_a, t_stack *stack_b)
{
	int	divisions[5];

	divisions[0] = 1;
	divisions[1] = node_num / 3;
	divisions[2] = node_num / 2;
	divisions[3] = node_num * 3 / 4;
	divisions[4] = node_num;
	push_lump_top(divisions[1], stack_a, stack_b);
	push_lump_top(divisions[2], stack_a, stack_b);
	push_lump_bottom(divisions[3], stack_a, stack_b);
	push_lump_top(node_num, stack_a, stack_b);
	sort_and_return(&divisions[3], stack_a, stack_b);
	sort_and_return(&divisions[2], stack_a, stack_b);
	sort_and_return(&divisions[1], stack_a, stack_b);
	sort_and_return(&divisions[0], stack_a, stack_b);
	pa(stack_a, stack_b);
}

static void	push_lump_top(int max, t_stack *stack_a, t_stack *stack_b)
{
	int	bottom;

	if (stack_a == NULL || stack_b == NULL \
	|| stack_a->top == NULL || stack_a->bottom == NULL)
		exit(1);
	bottom = stack_a->bottom->body;
	while (stack_a->top->body != bottom)
	{
		if (stack_a->top->body <= max)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	if (bottom <= max)
		pb(stack_a, stack_b);
}

static void	push_lump_bottom(int max, t_stack *stack_a, t_stack *stack_b)
{
	int	bottom;

	if (stack_a == NULL || stack_b == NULL \
	|| stack_a->top == NULL || stack_a->bottom == NULL)
		exit(1);
	bottom = stack_a->bottom->body;
	while (stack_a->top->body != bottom)
	{
		if (stack_a->top->body <= max)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else
			ra(stack_a);
	}
	if (bottom <= max)
	{
		pb(stack_a, stack_b);
		rb(stack_b);
	}
}

static void	sort_and_return(int *range, t_stack *stack_a, t_stack *stack_b)
{
	int	next;

	next = range[1];
	while (next > range[0])
	{
		while (stack_b->top->body > range[0])
		{
			if (stack_b->top->body == next)
				pa_and_proceed(&next, stack_a, stack_b);
			else
				rb(stack_b);
		}
		while (stack_b->bottom->body > range[0])
		{
			if (stack_b->top->body == next)
				pa_and_proceed(&next, stack_a, stack_b);
			else
				rrb(stack_b);
		}
	}
}

static void	pa_and_proceed(int *next, t_stack *stack_a, t_stack *stack_b)
{
	pa(stack_a, stack_b);
	*next -= 1;
}
