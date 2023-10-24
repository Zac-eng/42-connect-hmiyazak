/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:29:03 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/24 22:06:02 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int		fx(int x, int y, int a);
int		fy(int x, int y, int b);
void	show_input_choice(void);
void	julia_operation(int z_0);
void	mandelbrot_operation(int c);
int		escape_close(int keycode, t_vars *vars);
int		ft_strcmp(char *lhs, char *rhs);
int		ft_atoi(char *input);

#endif
