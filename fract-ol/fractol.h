/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:29:03 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/24 19:43:22 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int		fx(int x, int y, int a);
int		fy(int x, int y, int b);
void	julia_operation(int c);
void	mandelbrot_operation(int c);
int		ft_strcmp(char *lhs, char *rhs);

#endif
