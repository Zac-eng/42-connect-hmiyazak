/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:28:42 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/26 04:06:42 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	create_julia_image(t_data *img, double c_r, double c_i);

void	julia_operation(double c_r, double c_i)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "julia set");
	init_data(vars.mlx, &img);
	create_julia_image(&img, c_r, c_i);
	if (img.img == NULL)
		exit(1);
	mlx_window_options(&vars, &img);
}

static void	create_julia_image(t_data *img, double c_r, double c_i)
{
	double	zn[2];
	double	real_tmp;
	int		iter;

	zn[0] = 0.0;
	zn[1] = 0.0;
	iter = 0;
	while (iter < INT_MAX)
	{
		real_tmp = zn[0];
		zn[0] = pow(zn[0], 2.0) - pow(zn[1], 2.0) + c_r;
		zn[1] = 2 * real_tmp * zn[1] + c_i;
		put_pixel_img(img, zn[0], zn[1], 0x00FFFFFF);
		iter += 1;
	}
}
