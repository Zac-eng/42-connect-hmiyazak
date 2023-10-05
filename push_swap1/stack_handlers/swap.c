/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:24:16 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/05 16:02:33 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap(t_node *node_top)
{
	int	result;

	if (node_top == NULL || node_top->next == NULL
		|| node_top->previous != NULL)
		return (-1);
	result = swap_element(node_top, node_top->next);
	return (result);
}

int	swap_a(t_node *a_top)
{
	int	result;

	result = swap(a_top);
	if (result == 0)
		write(1, "sa\n", 3);
	return (result);
}

int	swap_b(t_node *b_top)
{
	int	result;

	result = swap(b_top);
	if (result == 0)
		write(1, "sb\n", 3);
	return (result);
}

int	swap_s(t_node *a_top, t_node *b_top)
{
	int	result;

	result = 0;
	if (a_top == NULL || a_top->next == NULL || a_top->previous != NULL)
		return (-1);
	if (b_top == NULL || b_top->next == NULL || b_top->previous != NULL)
		return (-1);
	result += swap(a_top);
	result += swap(b_top);
	if (result < 0)
		return (-1);
	write (1, "ss\n", 3);
	return (0);
}
