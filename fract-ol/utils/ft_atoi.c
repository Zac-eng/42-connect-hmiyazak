/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:04:04 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/24 21:38:00 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	check_minus(char **input);
static int	check_overflow(int minus_flag, int return_num, char input);

int	ft_atoi(char *input)
{
	int	minus_flag;
	int	return_num;

	return_num = 0;
	minus_flag = check_minus(&input);
	while (*input != '\0')
	{
		if (check_overflow(minus_flag, return_num, *input) == 1)
		{
			show_input_choice();
			exit(0);
		}
		return_num = return_num * 10 + (*input - '0');
		input += 1;
	}
	if (minus_flag == 1)
		return_num *= -1;
	return (return_num);
}

static int	check_minus(char **input)
{
	if (**input == '-')
	{
		*input += 1;
		return (1);
	}
	else
		return (0);
}

static int	check_overflow(int minus_flag, int return_num, char input)
{
	int	next_num;

	next_num = input - '0';
	if (minus_flag == 1)
	{
		if (return_num > INT_MAX / 10)
			return (1);
		else if (return_num < INT_MAX / 10)
			return (0);
		if (next_num > INT_MAX % 10 + 1)
			return (1);
		else
			return (0);
	}
	else
	{
		if (return_num > INT_MAX / 10)
			return (1);
		else if (return_num < INT_MAX / 10)
			return (0);
		if (next_num > INT_MAX % 10)
			return (1);
		else
			return (0);
	}
}
