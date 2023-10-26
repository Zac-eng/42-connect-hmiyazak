/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:28:42 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/26 20:53:16 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	create_julia_image(t_data *img, double *c, int *size);
static int	isin_julia(double *zn, double *c);

void	julia_operation(double *c)
{
	t_vars	vars;
	t_data	img;
	int		size[2];

	size[0] = 1920;
	size[1] = 1080;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, size[0], size[1], "julia set");
	init_data(vars.mlx, &img);
	if (img.img == NULL)
		exit(1);
	create_julia_image(&img, &c[0], &size[0]);
	mlx_window_options(&vars, &img);
}

static void	create_julia_image(t_data *img, double *c, int *size)
{
	double	z0[2];
	int		iter[2];

	iter[0] = 0;
	iter[1] = 0;
	while (iter[0] <= size[0])
	{
		while (iter[1] <= size[1])
		{
			z0[0] = -2.0 + (double)iter[0] * 4.0 / (double)size[0];
			z0[1] = -2.0 + (double)iter[1] * 4.0 / (double)size[1];
			if (isin_julia(&z0[0], c) == 1)
				put_pixel_img(img, iter[0], iter[1], 0x00FFFFFF);
			iter[1] += 1;
		}
		iter[1] = 0;
		iter[0] += 1;
	}
}

static int	isin_julia(double *zn, double *c)
{
	double	real_tmp;
	int		iter;

	iter = 0;
	while (iter < 200)
	{
		real_tmp = zn[0];
		zn[0] = pow(zn[0], 2.0) - pow(zn[1], 2.0) + c[0];
		zn[1] = 2 * real_tmp * zn[1] + c[1];
		iter += 1;
	}
	if (real_tmp - zn[0] < 0.001)
		return (1);
	else
		return (0);
}
