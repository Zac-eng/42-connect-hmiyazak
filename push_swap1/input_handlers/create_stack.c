/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:18:50 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/05 21:56:55 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_node(int argc, char **argv);

t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		node_num;
	int		*node_list;

	node_num = count_node(argc, argv);
	node_list = (int *)malloc(sizeof(int) * node_num);
	if (node_list == NULL)
		exit(1);
	create_input_list(argc, argv, node_list);
	compress_list(node_num, node_list);
	stack = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (stack == NULL)
		exit(1);
	stack->max_size = node_num;
	// create_node(node_num, node_list, stack->top, stack->bottom);
	return (stack);
}

static int	count_node(int argc, char **argv)
{
	int		node_num;
	char	*num_set;

	node_num = 0;
	num_set = argv[1];
	if (argc <= 1)
		exit(0);
	else if (argc > 2)
		return (argc - 1);
	else
	{
		while (*num_set != '\0')
		{
			while (ft_isspace(*num_set) == 1)
				num_set += 1;
			if (*num_set != '\0')
				node_num += 1;
			while (ft_isspace(*num_set) == 0)
				num_set += 1;
		}
		return (node_num);
	}
}

