/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:18:50 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/06 19:09:14 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int		count_node(int argc, char **argv);
static t_stack	*initialize_stack(int node_num);

t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		node_num;
	int		*node_list;
	int		iterator;

	iterator = 0;
	node_num = count_node(argc, argv);
	node_list = (int *)malloc(sizeof(int) * node_num);
	if (node_list == NULL)
		exit(1);
	create_input_list(argc, argv, node_list);
	compress_list(node_num, node_list);
	stack = initialize_stack(node_num);
	while (iterator < node_num)
	{
		push_top(stack, node_list[iterator]);
		iterator += 1;
	}
	return (stack);
}

static t_stack	*initialize_stack(int node_num)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (new_stack == NULL)
		exit(1);
	new_stack->current_size = 0;
	new_stack->max_size = node_num;
	new_stack->top = NULL;
	new_stack->bottom = NULL;
	return (new_stack);
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
			while (ft_isspace(*num_set) == 0 && *num_set != '\0')
				num_set += 1;
		}
		return (node_num);
	}
}

