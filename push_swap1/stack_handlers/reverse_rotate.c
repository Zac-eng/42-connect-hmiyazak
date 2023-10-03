/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:21:00 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/09/16 11:42:27 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	reverse_rotate(t_stack *stack_top)
{
	t_stack	*current_position;

	if (stack_top == NULL || stack_top->next == NULL)
		return (0);
	if (stack_top->previous != NULL)
		return (-1);
	current_position = stack_top;
	while (current_position->next->next != NULL)
		current_position = current_position->next;
	current_position->next->next = stack_top;
	current_position->next->previous = NULL;
	stack_top->previous = current_position->next;
	current_position->next = NULL;
	return (0);
}

int	rev_rotate_a(t_stack *a_top)
{
	int	result;

	result = reverse_rotate(a_top);
	if (result == 0)
		write(1, "rra\n", 4);
	return (result);
}

int	rev_rotate_b(t_stack *b_top)
{
	int	result;

	result = reverse_rotate(b_top);
	if (result == 0)
		write(1, "rrb\n", 4);
	return (result);
}

int	rev_rotate_r(t_stack *a_top, t_stack *b_top)
{
	int	result;

	result = 0;
	result += reverse_rotate(a_top);
	result += reverse_rotate(b_top);
	if (result < 0)
		return (-1);
	write(1, "rrr\n", 4);
	return (0);
}
