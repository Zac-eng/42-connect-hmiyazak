/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:38:21 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/09/16 11:27:43 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_a(t_stack *a_top, t_stack *b_top)
{
	if (a_top == NULL || a_top->previous != NULL)
		return (-1);
	if (a_top->next != NULL)
		a_top->next->previous = NULL;
	a_top->next = b_top;
	if (b_top != NULL)
		b_top->previous = a_top;
	write(1, "pa\n", 3);
	return (0);
}

int	push_b(t_stack *a_top, t_stack *b_top)
{
	if (b_top == NULL || b_top->previous != NULL)
		return (-1);
	if (b_top->next != NULL)
		b_top->next->previous = NULL;
	b_top->next = a_top;
	if (a_top != NULL)
		a_top->previous = b_top;
	write(1, "pb\n", 3);
	return (0);
}
