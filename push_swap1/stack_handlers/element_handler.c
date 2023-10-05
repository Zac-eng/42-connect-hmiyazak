/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:25:38 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/05 15:15:21 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*generate_element(t_stack *previous, int stack_content)
{
	t_stack	*new_element;

	new_element = (t_stack *)malloc(sizeof(t_stack *) * 1);
	if (new_element == NULL)
		exit(1);
	printf("%p, %p\n", new_element, previous);
	new_element->body = stack_content;
	new_element->previous = previous;
	new_element->next = NULL;
	if (previous != NULL)
	{
		previous->next = new_element;
		printf("%p, %p\n\n", previous, previous->next);
	}
	return (new_element);
}

int	swap_element(t_stack *first, t_stack *second)
{
	if (first == NULL || second == NULL)
		return (-1);
	if (first->next != second)
		return (-1);
	second->previous = first->previous;
	first->previous = second;
	first->next = second->next;
	second->next = first;
	return (0);
}


