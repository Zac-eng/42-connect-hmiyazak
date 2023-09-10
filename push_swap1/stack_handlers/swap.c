/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:24:16 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/09/10 14:37:41 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap_a(t_stack *a_top)
{
	int	result;

	if (a_top == NULL || a_top->next == NULL || a_top->previous != NULL)
		return (-1);
	result = swap_element(a_top, a_top->next);
	return (result);
}

int	swap_b(t_stack *b_top)
{
	int	result;

	if (b_top == NULL || b_top->next == NULL || b_top->previous != NULL)
		return (-1);
	result = swap_element(b_top, b_top->next);
	return (result);
}

int	swap_s(t_stack *a_top, t_stack *b_top)
{
	int	result;

	result = 0;
	if (a_top == NULL || a_top->next == NULL || a_top->previous != NULL)
		return (-1);
	if (b_top == NULL || b_top->next == NULL || b_top->previous != NULL)
		return (-1);
	result += swap_a(a_top);
	result += swap_b(b_top);
	if (result < 0)
		return (-1);
	return (0);
}
