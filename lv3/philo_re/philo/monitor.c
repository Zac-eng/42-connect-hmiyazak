/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:27:27 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/05/05 18:58:14 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_table *table)
{
	long int	c_time;
	long int	last_eat;
	int			iter;

	while (1)
	{
		iter = 0;
		get_time_ms(&c_time);
		while (iter < get_philonum(table))
		{
			if (get_numfinished(table) == get_philonum(table))
				return ;
			last_eat = get_last_eat(&table->philos[iter]);
			if (last_eat < 0)
				break ;
			if (c_time - last_eat > get_time(table, 'd'))
			{
				died(iter + 1, table);
				return ;
			}
			iter++;
		}
	}
	return ;
}

