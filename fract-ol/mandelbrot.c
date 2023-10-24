/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:42:59 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/24 23:19:47 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_operation(int c)
{
	t_vars	vars;
	t_data	img;

	c++;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "mandelbrot set");
	init_data(vars.mlx, &img);
	my_mlx_pixel_put(&img, 960, 540, 0x00FFFFFF);
	if (img.img == NULL)
		exit(1);
	mlx_key_hook(vars.win, escape_close, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
