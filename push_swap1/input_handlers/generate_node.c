/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:43:29 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/06 13:55:10 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*generate_element(t_node *previous, int node_content);

// void	create_node(int listsize, int *refarence, t_stack stack)
// {
// 	int	index;

// 	index = 0;
// 	stack->top = generate_element(NULL, ref[index]);
// 	index += 1;
// 	while (index < lstsize)
// 	{
		
// 	}
//}

t_node	*generate_element(t_node *previous, int node_content)
{
	t_node	*new_element;

	new_element = (t_node *)malloc(sizeof(t_node *) * 1);
	if (new_element == NULL)
		exit(1);
	new_element->body = node_content;
	new_element->previous = previous;
	new_element->next = NULL;
	if (previous != NULL)
		previous->next = new_element;
	return (new_element);
}
