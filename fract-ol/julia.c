/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:28:42 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/28 17:12:11 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	create_julia_image(t_data *img, int *size);
static int	isin_julia(double *c);

void	julia_operation(void)
{
	t_vars	vars;
	t_data	img;
	int		size[2];

	size[0] = 1080;
	size[1] = 1080;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, size[0], size[1], "julia set");
	init_data(vars.mlx, &img);
	if (img.img == NULL)
		exit(1);
	create_julia_image(&img, &size[0]);
	mlx_window_options(&vars, &img);
}

static void	create_julia_image(t_data *img, int *size)
{
	double	c[2];
	int		iter[2];
	int		one_side;

	iter[0] = 0;
	iter[1] = 0;
	if (size[0] < size[1])
		one_side = size[0];
	else
		one_side = size[1];
	while (iter[0] < size[0])
	{
		while (iter[1] < size[1])
		{
			c[0] = -2.0 + (double)iter[0] * 4.0 / (double)one_side;
			c[1] = 2.0 - (double)iter[1] * 4.0 / (double)one_side;
			if (isin_julia(&c[0]) == 1)
				put_pixel_img(img, iter[0], iter[1], 0x00FFFACD);
			else if (isin_julia(&c[0]) == 0)
				put_pixel_img(img, iter[0], iter[1], 0x00FF9999);
			iter[1] += 1;
		}
		iter[1] = 0;
		iter[0] += 1;
	}
}

static int	isin_julia(double *c)
{
	double	zn[2];
	double	zn_prev[2];
	int		iter;

	iter = 0;
	c[0] = 0.0;
	c[1] = 0.0;
	while (iter < 100)
	{
		zn_prev[0] = zn[0];
		zn_prev[1] = zn[1];
		zn[0] = pow(zn_prev[0], 2.0) - pow(zn_prev[1], 2.0) + c[0];
		zn[1] = 2 * zn_prev[0] * zn_prev[1] + c[1];
		iter += 1;
	}
	if (zn[0] * zn[0] + zn[1] * zn[1] < 4)
		return (1);
	else
		return (0);
}
