/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:13:57 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/09/10 16:48:09 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rotate_a(t_stack *a_top)
{
	t_stack	*current_position;

	if (a_top == NULL || a_top->next == NULL)
		return (0);
	if (a_top->previous != NULL)
		return (-1);
	current_position = a_top->next;
	a_top->next->previous = NULL;
	a_top->next = NULL;
	while (current_position->next != NULL)
		current_position = current_position->next;
	current_position->next = a_top;
	a_top->previous = current_position;
	return (0);
}

int	rotate_b(t_stack *b_top)
{
	t_stack	*current_position;

	if (b_top == NULL || b_top->next == NULL)
		return (0);
	if (b_top->previous != NULL)
		return (-1);
	current_position = b_top->next;
	b_top->next->previous = NULL;
	b_top->next = NULL;
	while (current_position->next != NULL)
		current_position = current_position->next;
	current_position->next = b_top;
	b_top->previous = current_position;
	return (0);
}
