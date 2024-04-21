/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:47:44 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/11/25 20:10:35 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_time_ms(double *time)
{
	t_time	current_time;

	if (time == NULL)
		return (-1);
	if (gettimeofday(&current_time, NULL) != 0)
		return (-1);
	*time = current_time.tv_sec * 1000.0 + current_time.tv_usec / 1000.0;
	return (0);
}

double	create_timestamp(double c_time, t_table *table)
{
	return (c_time - table->start_time);
}
