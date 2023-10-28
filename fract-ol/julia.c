/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:28:42 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/28 18:02:50 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	create_julia_image(t_data *img, int *size, double *z0);
static int	return_color(double *c, double *z0);

void	julia_operation(double *z0)
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
	create_julia_image(&img, &size[0], z0);
	mlx_window_options(&vars, &img);
}

static void	create_julia_image(t_data *img, int *size, double *z0)
{
	double	c[2];
	int		iter[2];

	iter[0] = 0;
	iter[1] = 0;
	while (iter[0] < size[0])
	{
		while (iter[1] < size[1])
		{
			c[0] = -3.0 + (double)iter[0] * 6.0 / (double)size[0];
			c[1] = 3.0 - (double)iter[1] * 6.0 / (double)size[1];
			put_pixel_img(img, iter[0], iter[1], return_color(&c[0], z0));
			iter[1] += 1;
		}
		iter[1] = 0;
		iter[0] += 1;
	}
}

static int	return_color(double *c, double *z0)
{
	double	zn[2];
	double	zn_prev[2];
	int		iter;

	iter = 0;
	zn[0] = z0[0];
	zn[1] = z0[1];
	while (iter < 100 && zn[0] * zn[0] + zn[1] * zn[1] < 4)
	{
		zn_prev[0] = zn[0];
		zn_prev[1] = zn[1];
		zn[0] = pow(zn_prev[0], 2.0) - pow(zn_prev[1], 2.0) + c[0];
		zn[1] = 2 * zn_prev[0] * zn_prev[1] + c[1];
		iter += 1;
	}
	if (zn[0] * zn[0] + zn[1] * zn[1] < 4)
		return (0x00FFFACD);
	else
		return (0x006A5ACD + (zn[0] * zn[0] + zn[1] * zn[1]) * 1.2);
}
