/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:25:38 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/05 16:02:55 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*generate_element(t_node *previous, int node_content)
{
	t_node	*new_element;

	new_element = (t_node *)malloc(sizeof(t_node *) * 1);
	if (new_element == NULL)
		exit(1);
	printf("%p, %p\n", new_element, previous);
	new_element->body = node_content;
	new_element->previous = previous;
	new_element->next = NULL;
	if (previous != NULL)
	{
		previous->next = new_element;
		printf("%p, %p\n\n", previous, previous->next);
	}
	return (new_element);
}

int	swap_element(t_node *first, t_node *second)
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


