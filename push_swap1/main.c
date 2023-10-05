/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:22:07 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/05 16:03:53 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*generate_element(t_node *previous, int node_content);
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_node	*first_element;
	t_node	*second_element;
	t_node	*third_element;

	printf("%d, %s\n", argc, argv[0]);
	first_element = generate_element(NULL, 5);
	second_element = generate_element(first_element, 4);
	third_element = generate_element(second_element, 9);
	printf("%d\n", rotate_a(first_element));
	return (0);
}
