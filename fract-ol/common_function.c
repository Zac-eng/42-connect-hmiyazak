/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:36:08 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/26 19:40:49 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	mlx_window_options(t_vars *vars, t_data *img)
{
	mlx_hook(vars->win, 2, 1L << 0, escape_close, vars);
	mlx_hook(vars->win, 17, 1L << 2, cross_close, vars);
	// mlx_hook(vars->win, 5, 1L << 18, expand, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	mlx_loop(vars->mlx);
}

void	put_pixel_img(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_data(void *mlx, t_data *d)
{
	d->img = mlx_new_image(mlx, 1920, 1080);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, \
		&d->endian);
}
