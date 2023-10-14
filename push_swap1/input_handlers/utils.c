/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:36:54 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/14 13:35:02 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_minus(char **should_num);
void		error_and_exit(void);

//admit input "-0" and "00" but decline " ", "\n", "-", and "- ".

int	atoi_or_exit(char *should_num)
{
	int	return_num;
	int	minus_flag;

	return_num = 0;
	if (*should_num == '\0' || ft_isspace(*should_num) == 1)
		error_and_exit();
	minus_flag = check_minus(&should_num);
	while (*should_num != '\0' && ft_isspace(*should_num) == 0)
	{
		if ('0' <= *should_num && *should_num <= '9')
		{
			return_num = return_num * 10 + (*should_num - '0');
			should_num += 1;
		}
		else
			error_and_exit();
	}
	if (minus_flag == 1)
		return_num *= -1;
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

static int	check_minus(char **should_num)
{
	if (**should_num == '-')
	{
		*should_num += 1;
		if (ft_isspace(**should_num) == 1 || **should_num == '\0')
			error_and_exit();
		else
			return (1);
	}
	return (0);
}

void	error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
