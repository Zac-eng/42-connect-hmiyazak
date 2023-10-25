/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:42:59 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/26 04:45:25 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	create_mandelbrot_image(t_data *img, double c_r, double c_i);

void	mandelbrot_operation(double c_r, double c_i)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "mandelbrot set");
	init_data(vars.mlx, &img);
	if (img.img == NULL)
		exit(1);
	create_mandelbrot_image(&img, c_r, c_i);
	mlx_window_options(&vars, &img);
}

static void	create_mandelbrot_image(t_data *img, double c_r, double c_i)
{
	double	zn[2];
	double	real_tmp;
	int		iter;

	zn[0] = 0.0;
	zn[1] = 0.0;
	iter = 0;
	while (iter < 1000)
	{
		real_tmp = zn[0];
		zn[0] = pow(zn[0], 2.0) - pow(zn[1], 2.0) + c_r;
		zn[1] = 2 * real_tmp * zn[1] + c_i;
		printf("%f, %f\n", zn[0], zn[1]);
		if (zn[0] > 2 || zn[1] > 2)
			show_input_choice();
		put_pixel_img(img, 960 + zn[0] * 480, 540 + zn[1] * 270, 0x00FFFFFF);
		iter += 1;
	}
}
