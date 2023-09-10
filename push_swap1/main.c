/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:22:07 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/09/10 14:31:29 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_input(int ac, char **av);

#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc > 1)
		check_input(argc, &argv[0]);
	t_stack *elem1 = generate_element(NULL, *argv[1] - '0');
	t_stack *elem2 = generate_element(elem1, *argv[2] - '0');
	swap_element(elem1, elem2);
	printf("%p, %p, %d, %p\n", elem1, elem1->previous, elem1->body, elem1->next);
	printf("%p, %p, %d, %p\n", elem2, elem2->previous, elem2->body, elem2->next);
	return (0);
}

static void	check_input(int ac, char **av)
{
	int	counter;

	counter = 1;
	while (counter < ac)
	{
		if (check_arg(av[counter]) == 0)
			counter += 1;
		else
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	}
}
