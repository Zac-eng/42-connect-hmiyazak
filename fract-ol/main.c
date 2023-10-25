/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:30:21 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/26 04:32:44 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_which_set(int argc, char *argv);

int	main(int argc, char *argv[])
{
	int		which_set;
	double	real_parameter;
	double	imaginary_parameter;

	which_set = check_which_set(argc, argv[1]);
	real_parameter = ft_atof(argv[2]);
	imaginary_parameter = ft_atof(argv[3]);
	printf("%f\n", hypot(real_parameter, imaginary_parameter));
	if (hypot(real_parameter, imaginary_parameter) > 2)
		show_input_choice();
	if (which_set == 1)
		julia_operation(real_parameter, imaginary_parameter);
	else if (which_set == 2)
		mandelbrot_operation(real_parameter, imaginary_parameter);
	return (0);
}

static int	check_which_set(int argc, char *argv)
{
	if (argc != 4)
		show_input_choice();
	if (argv == NULL)
		exit(1);
	if (ft_strcmp(argv, "julia") == 0 && ft_strcmp(argv, "mandelbrot") == 0)
		show_input_choice();
	if (ft_strcmp(argv, "julia") == 1)
		return (1);
	if (ft_strcmp(argv, "mandelbrot") == 1)
		return (2);
	exit(0);
}

void	show_input_choice(void)
{
	ft_printf("Input should follow either of the formats below\n");
	ft_printf("1: mandelbrot <real part> <imaginary part>\n");
	ft_printf("2: julia <real part> <imaginary part>\n");
	ft_printf("\n");
	ft_printf("Attention:\n");
	ft_printf("mandelbrot set |zk| should be in range of -2 - 2\n");
	ft_printf("julia set parameter should be \n");
	exit(0);
}
