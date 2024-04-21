/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:56:24 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/11/27 14:07:21 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo, t_table *table)
{
	double	c_time;
	double	timestamp;

	if (philo == NULL || table == NULL)
		return (0);
	if (lock_forks(philo) != 0)
		return (2);
	if (get_time_ms(&c_time) != 0)
		return (-1);
	timestamp = create_timestamp(c_time, table);
	if (c_time - philo->last_eat < table->time_d_e_s[0] && table->all_alive)
	{
		printf("%f %d has taken a fork\n", timestamp, philo->philo_id);
		return (0);
	}
	unlock_forks(philo);
	if (table->all_alive == 1)
	{
		died(philo->philo_id, table);
		return (1);
	}
	else
		return (2);
}

int	start_eating(t_philo *philo, t_table *table)
{
	double	c_time;
	double	timestamp;

	if (philo == NULL || table == NULL)
		return (0);
	if (get_time_ms(&c_time) != 0)
		return (-1);
	timestamp = create_timestamp(c_time, table);
	printf("%f %d is eating\n", timestamp, philo->philo_id);
	if (clean_wait(c_time - philo->last_eat, table, "eat") != 0)
	{
		died(philo->philo_id, table);
		unlock_forks(philo);
		return (1);
	}
	get_time_ms(&(philo->last_eat));
	if (unlock_forks(philo) != 0)
		return (-1);
	if (table->all_alive == 0)
		return (2);
	return (0);
}

int	start_sleeping(t_philo *philo, t_table *table)
{
	double	c_time;
	double	timestamp;

	if (philo == NULL || table == NULL)
		return (0);
	if (get_time_ms(&c_time) != 0)
		return (-1);
	timestamp = create_timestamp(c_time, table);
	printf("%f %d is sleeping\n", timestamp, philo->philo_id);
	if (clean_wait(c_time - philo->last_eat, table, "sleep") != 0)
	{
		died(philo->philo_id, table);
		return (1);
	}
	else if (table->all_alive == 0)
		return (2);
	return (0);
}

int	start_thinking(t_philo *philo, t_table *table)
{
	double	c_time;
	double	timestamp;

	if (philo == NULL || table == NULL)
		return (0);
	if (get_time_ms(&c_time) != 0)
		return (-1);
	timestamp = create_timestamp(c_time, table);
	printf("%f %d is thinking\n", timestamp, philo->philo_id);
	return (0);
}

int	died(int philo_id, t_table *table)
{
	double	c_time;
	double	timestamp;

	if (table == NULL)
		return (-1);
	if (get_time_ms(&c_time) != 0)
		return (-1);
	if (pthread_mutex_lock(&(table->alive_mutex)) == 0)
	{
		if (table->all_alive == 1)
		{
			table->all_alive = 0;
			timestamp = create_timestamp(c_time, table);
			printf("%f %d died\n", timestamp, philo_id);
		}
		pthread_mutex_unlock(&(table->alive_mutex));
	}
	return (0);
}
