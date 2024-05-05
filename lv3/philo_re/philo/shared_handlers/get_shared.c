/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shared.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:20:02 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/05/05 18:28:45 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_numfinished(t_table *table)
{
	int	num_finished;

	if (pthread_mutex_lock(&table->finished_mutex) == 0)
	{
		num_finished = table->num_finished;
		pthread_mutex_unlock(&table->finished_mutex);
		return (num_finished);
	}
	else
		return (-1);
}

int	get_time(t_table *table, const char which_time)
{
	int	retval;

	retval = 0;
	if (pthread_mutex_lock(&table->time_mutex) == 0)
	{
		if (which_time == 'd')
			retval = table->time_d_e_s[0];
		else if (which_time == 'e')
			retval = table->time_d_e_s[1];
		else if (which_time == 's')
			retval = table->time_d_e_s[2];
		else
			retval = -1;
		pthread_mutex_unlock(&table->time_mutex);
	}
	return (retval);
}

int	get_philonum(t_table *table)
{
	int	philonum;

	if (pthread_mutex_lock(&table->philonum_mutex) == 0)
	{
		philonum = table->philo_num;
		pthread_mutex_unlock(&table->philonum_mutex);
		return (philonum);
	}
	else
		return (-1);
}

long int	get_start_time(t_table *table)
{
	long int	start_time;

	if (pthread_mutex_lock(&table->start_time_mutex) == 0)
	{
		start_time = table->start_time;
		pthread_mutex_unlock(&table->start_time_mutex);
		return (start_time);
	}
	else
		return (-1);
}

long int	get_last_eat(t_philo *philo)
{
	long int	last_eat;

	if (pthread_mutex_lock(&philo->last_eat_mutex) == 0)
	{
		last_eat = philo->last_eat;
		pthread_mutex_unlock(&philo->last_eat_mutex);
		return (last_eat);
	}
	else
		return (-1);
}
