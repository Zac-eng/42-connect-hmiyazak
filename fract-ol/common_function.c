/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:36:08 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/24 23:03:38 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	escape_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
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
