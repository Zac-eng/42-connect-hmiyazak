/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:22:07 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/03 15:09:16 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
int	main(int argc, char *argv[])
{
	int		index;
	t_stack	*first_element;

	index = 0;
	first_element = NULL;
	if (argc > 1)
		first_element = create_stack(argc, &argv[0]);
	printf("%d\n", first_element->body);
	printf("%d\n", first_element->next->body);
	// first_element = create_stack(argc - 1, argv[0]);
	// printf("%d\n", first_element->body);
	// printf("%d\n", first_element->next->body);
	return (0);
}

// static void	check_input(int ac, char **av)
// {
// 	int	counter;

// 	if (ac == 2)
// 		check_single_arg();
// 	else
// 	{
// 		counter = 1;
// 		while (counter < ac)
// 		{
// 			if (check_multiple_arg(av[counter]) == 0)
// 				counter += 1;
// 			else
// 			{
// 				write(1, "Error\n", 6);
// 				exit(1);
// 			}
// 		}
// 	}
// }
