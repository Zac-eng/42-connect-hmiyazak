/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:29:03 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/28 17:59:00 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <float.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	show_input_choice(void);
void	julia_operation(double *z0);
void	mandelbrot_operation(void);
void	mlx_window_options(t_vars *vars, t_data *img);
int		escape_close(int keycode, t_vars *vars);
int		cross_close(int keycode);
void	put_pixel_img(t_data *data, int x, int y, int color);
void	init_data(void *mlx, t_data *d);
int		ft_strcmp(char *lhs, char *rhs);
double	ft_atof(char *input);

#endif
