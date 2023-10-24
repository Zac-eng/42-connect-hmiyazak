/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:30:21 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/24 22:05:28 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_which_set(int argc, char *argv);

int	main(int argc, char *argv[])
{
	int		which_set;
	int		parameter;

	which_set = check_which_set(argc, argv[1]);
	parameter = ft_atoi(argv[2]);
	ft_printf("%d\n", parameter);
	if (which_set == 1)
		julia_operation(parameter);
	else if (which_set == 2)
		mandelbrot_operation(parameter);
	return (0);
}

static int	check_which_set(int argc, char *argv)
{
	if (argc != 3)
	{
		show_input_choice();
		exit(0);
	}
	if (argv == NULL)
		exit(1);
	if (ft_strcmp(argv, "julia") == 0 && ft_strcmp(argv, "mandelbrot") == 0)
	{
		show_input_choice();
		exit(0);
	}
	if (ft_strcmp(argv, "julia") == 1)
		return (1);
	if (ft_strcmp(argv, "mandelbrot") == 1)
		return (2);
	exit(0);
}

void	show_input_choice(void)
{
	ft_printf("Input should follow either of the formats below\n");
	ft_printf("1: mandelbrot <parameter for \"C\">\n");
	ft_printf("2: julia <parameter for \"Z_0\">\n");
	ft_printf("\n");
	ft_printf("Attention:\n");
	ft_printf("mandelbrot set parameter should be in range of -2 - 2\n");
	ft_printf("julia set parameter should be \n");
}
