/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_shared.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:55:00 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/05/05 18:49:21 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	switch_allalive(t_table *table)
{
	if (pthread_mutex_lock(&table->finished_mutex) == 0)
	{
		table->num_finished = get_philonum(table);
		pthread_mutex_unlock(&table->finished_mutex);
	}
}

void	increment_finishedeat(t_table *table)
{
	if (pthread_mutex_lock(&table->finished_mutex) == 0)
	{
		table->num_finished++;
		pthread_mutex_unlock(&table->finished_mutex);
	}
}

int	update_last_eat(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->last_eat_mutex) == 0)
	{
		if (get_time_ms(&philo->last_eat) == -1)
		{
			pthread_mutex_unlock(&philo->last_eat_mutex);
			return (-1);
		}
		pthread_mutex_unlock(&philo->last_eat_mutex);
		return (0);
	}
	else
		return (-1);
}
