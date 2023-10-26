/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:51:39 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/26 19:42:12 by hmiyazak         ###   ########.fr       */
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

int	cross_close(int keycode)
{
	if (keycode < 0)
		exit(0);
	else
		return (0);
}

// int	expand(int keycode, int x, int y, t_vars *vars)
// {
// 	vars->
// }
