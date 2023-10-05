/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:18:49 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/05 11:56:27 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		atoi_or_exit(char *charactor);
static int		ft_isspace(char c);
static t_stack	*process_single_arg(char *argument);
static t_stack	*process_multiple_arg(int argc, char **argv);

t_stack	*create_stack(int argc, char **argv)
{
	if (argc == 1)
		return (NULL);
	else if (argc == 2)
		return (process_single_arg(argv[1]));
	else
		return (process_multiple_arg(argc, argv));
}

static t_stack	*process_single_arg(char *argument)
{
	t_stack	*top_element_ptr;
	t_stack	*current_ptr;

	top_element_ptr = NULL;
	current_ptr = NULL;
	while (*argument != '\0')
	{
		while (ft_isspace(*argument) == 1)
			argument += 1;
		if (*argument != '\0')
		{
			current_ptr = generate_element(current_ptr, atoi_or_exit(argument));
			if (current_ptr == NULL)
				exit(1);
			if (top_element_ptr == NULL)
				top_element_ptr = current_ptr;
		}
		while (ft_isspace(*argument) == 0 && *argument != '\0')
			argument += 1;
	}
	return (top_element_ptr);
}

static t_stack	*process_multiple_arg(int argc, char **argv)
{
	int		iterator;
	t_stack	*last_elem;
	t_stack	*first_elem;

	iterator = 1;
	last_elem = NULL;
	first_elem = NULL;
	while (iterator < argc)
	{
		last_elem = generate_element(last_elem, atoi_or_exit(argv[iterator]));
		if (last_elem == NULL)
			exit(1);
		if (first_elem == NULL)
			first_elem = last_elem;
		iterator += 1;
	}
	return (first_elem);
}

static int	atoi_or_exit(char *should_num)
{
	int	return_num;

	return_num = 0;
	while (*should_num != '\0')
	{
		if ('0' <= *should_num && *should_num <= '9')
		{
			return_num = return_num * 10 + (*should_num - '0');
			should_num += 1;
		}
		else if (ft_isspace(*should_num) == 1)
			return (return_num);
		else
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	}
	return (return_num);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'\
		|| c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}
