/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:13:57 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/05 16:02:17 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate(t_node *node_top)
{
	t_node	*current_position;

	if (node_top == NULL || node_top->next == NULL)
		return (0);
	if (node_top->previous != NULL)
		return (-1);
	current_position = node_top->next;
	node_top->next->previous = NULL;
	node_top->next = NULL;
	while (current_position->next != NULL)
		current_position = current_position->next;
	current_position->next = node_top;
	node_top->previous = current_position;
	return (0);
}

int	rotate_a(t_node *a_top)
{
	int	result;

	result = rotate(a_top);
	if (result == 0)
		write(1, "ra\n", 3);
	return (result);
}

int	rotate_b(t_node *b_top)
{
	int	result;

	result = rotate(b_top);
	if (result == 0)
		write(1, "rb\n", 3);
	return (result);
}

int	rotate_r(t_node *a_top, t_node *b_top)
{
	int	result_a;
	int	result_b;

	result_a = rotate(a_top);
	result_b = rotate(b_top);
	if (result_a == -1 || result_b == -1)
		return (-1);
	write(1, "rr\n", 3);
	return (0);
}
