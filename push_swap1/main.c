/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:22:07 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/06 18:11:39 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	//t_stack	*stack_b;

	t_node	*node1 = generate_element(NULL, 1);
	printf("%p, %p, %p\n", node1, node1->previous, node1->next);
	t_node	*node2 = generate_element(node1, 2);
	printf("%p, %p, %p\n", node2, node2->previous, node2->next);
	t_node	*node3 = generate_element(node2, 3);
	printf("%p, %p, %p\n", node3, node3->previous, node3->next);
	t_node	*node4 = generate_element(node3, 4);
	printf("%p, %p, %p\n\n", node4, node4->previous, node4->next);

	printf("%p, %p, %p\n", node1, node1->previous, node1->next);
	printf("%p, %p, %p\n", node2, node2->previous, node2->next);
	printf("%p, %p, %p\n", node3, node3->previous, node3->next);
	printf("%p, %p, %p\n", node4, node4->previous, node4->next);

	stack_a = create_stack(argc, &argv[0]);
	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	t_stack	*stack_a;
// 	//t_stack	*stack_b;

// 	stack_a = create_stack(argc, &argv[0]);
// 	return (0);
// }
