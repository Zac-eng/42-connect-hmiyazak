/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_input_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:25:14 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/05 21:30:38 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		create_input_list(int argc, char **argv, int *foundation);
static void	process_single_arg(char *argument, int *foundation);
static void	process_multiple_arg(int argc, char **argv, int *foundation);
int			atoi_or_exit(char *should_num);
int			ft_isspace(char c);

void	create_input_list(int argc, char **argv, int *foundation)
{
	if (argc <= 1)
		exit(0);
	if (argc == 2)
		process_single_arg(argv[1], foundation);
	else
		process_multiple_arg(argc, argv, foundation);
}

static void	process_single_arg(char *argument, int *foundation)
{
	int	index;

	index = 0;
	while (*argument != '\0')
	{
		while (ft_isspace(*argument) == 1)
			argument += 1;
		if (*argument != '\0')
		{
			foundation[index] = atoi_or_exit(argument);
			index += 1;
		}
		while (ft_isspace(*argument) == 0 && *argument != '\0')
			argument += 1;
	}
}

static void	process_multiple_arg(int argc, char **argv, int *foundation)
{
	int		index;

	index = 0;
	while (index + 1 < argc)
	{
		foundation[index] = atoi_or_exit(argv[index + 1]);
		index += 1;
	}
}

int	atoi_or_exit(char *should_num)
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

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'\
		|| c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}
