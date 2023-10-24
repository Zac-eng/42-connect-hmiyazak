/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:36:08 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/24 19:40:31 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fx(int x, int y, int a)
{
	return (x * x - y * y + a);
}

int	fy(int x, int y, int b)
{
	return (2 * x * y + b);
}
