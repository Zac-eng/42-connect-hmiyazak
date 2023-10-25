/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:04:04 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/26 04:00:27 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int		check_i_overflow(int sign, double return_num, char input);
static int		check_d_overflow(int sign, double num, double next_dbl);
static double	create_int_part(int sign, char *input);
static double	create_decimal_part(int sign, double num, char *input);

double	ft_atof(char *input)
{
	int		sign;
	double	return_num;

	if (input == NULL)
		show_input_choice();
	return_num = 0;
	sign = 1;
	if (*input == '-')
	{
		sign = -1;
		input += 1;
	}
	return_num = create_int_part(sign, input);
	while (*input != '\0' && *input != '.')
		input += 1;
	if (*input == '.')
	{
		input += 1;
		return_num = create_decimal_part(sign, return_num, input);
	}
	return (return_num);
}

static double	create_int_part(int sign, char *input)
{
	double	return_num;

	if (input == NULL || (*input == '0' && *(input + 1) != '.'))
		show_input_choice();
	if (*input == '\0' || *input == '0')
		return (0);
	return_num = (double)(*input - '0');
	return_num *= sign;
	input += 1;
	while (*input != '\0' && *input != '.')
	{
		if (*input < '0' || '9' < *input)
			show_input_choice();
		if (check_i_overflow(sign, return_num, *input) == 1)
			show_input_choice();
		return_num = return_num * 10 + (*input - '0') * sign;
		input += 1;
	}
	return (return_num);
}

static double	create_decimal_part(int sign, double num, char *input)
{
	double	return_num;
	double	digit;
	double	next_dbl;

	return_num = num;
	digit = 1;
	while (*input != '\0')
	{
		if (*input < '0' || '9' < *input)
			show_input_choice();
		next_dbl = (*input - '0') * pow(0.1, digit);
		if (check_d_overflow(sign, return_num, next_dbl) == 1)
			show_input_choice();
		return_num += next_dbl * sign;
		input += 1;
		digit += 1;
	}
	return (return_num);
}

static int	check_i_overflow(int sign, double return_num, char input)
{
	double	next_num;

	next_num = (double)(input - '0');
	if (sign < 0)
	{
		if (return_num > (DBL_MIN + next_num) / -10)
			return (1);
	}
	else
	{
		if (return_num > (DBL_MAX - next_num) / 10)
			return (1);
	}
	return (0);
}

static int	check_d_overflow(int sign, double num, double next_dbl)
{
	if (sign < 0)
	{
		if (num > DBL_MIN + next_dbl)
			return (1);
	}
	else
	{
		if (num > DBL_MAX - next_dbl)
			return (1);
	}
	return (0);
}
