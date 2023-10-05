/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:21:00 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/05 16:02:34 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	reverse_rotate(t_node *node_top)
{
	t_node	*current_position;

	if (node_top == NULL || node_top->next == NULL)
		return (0);
	if (node_top->previous != NULL)
		return (-1);
	current_position = node_top;
	while (current_position->next->next != NULL)
		current_position = current_position->next;
	current_position->next->next = node_top;
	current_position->next->previous = NULL;
	node_top->previous = current_position->next;
	current_position->next = NULL;
	return (0);
}

int	rev_rotate_a(t_node *a_top)
{
	int	result;

	result = reverse_rotate(a_top);
	if (result == 0)
		write(1, "rra\n", 4);
	return (result);
}

int	rev_rotate_b(t_node *b_top)
{
	int	result;

	result = reverse_rotate(b_top);
	if (result == 0)
		write(1, "rrb\n", 4);
	return (result);
}

int	rev_rotate_r(t_node *a_top, t_node *b_top)
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
