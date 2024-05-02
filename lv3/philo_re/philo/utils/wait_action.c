/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:18:02 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/05/02 16:41:52 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wait_action(long int wait_time_ms, t_table *table)
{
	long int	action_start;
	long int	time;

	get_time_ms(&action_start);
	get_time_ms(&time);
	while (time + 20 < action_start + wait_time_ms)
	{
		if (get_allalive(table) == 1)
			usleep(10000);
		else
			return (1);
		get_time_ms(&time);
	}
	while (time < action_start + wait_time_ms)
	{
		if (get_allalive(table) == 1)
			get_time_ms(&time);
		else
			return (1);
	}
	return (0);
}