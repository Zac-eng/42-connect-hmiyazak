/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:42:59 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/24 19:44:07 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	mandelbrot_operation(int c)
{
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "mandelbrot");
	mlx_pixel_put(vars.mlx, vars.win, 960, 540, 0x00FF0000);
	mlx_string_put(vars.mlx, vars.win, 100, 100, 0x00FFFFFF, "Good morning");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}
