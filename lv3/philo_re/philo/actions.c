/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:56:24 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/05/05 19:00:01 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo, t_table *table)
{
	long int	c_time;
	long int	timestamp;

	if (philo == NULL || table == NULL)
		return (0);
	if (lock_forks(philo) != 0)
		return (-1);
	if (get_time_ms(&c_time) != 0)
	{
		unlock_forks(philo);
		return (-1);
	}
	if (get_numfinished(table) < get_philonum(table))
	{
		timestamp = create_timestamp(c_time, table);
		printf("%ld %d has taken a fork\n", timestamp, philo->philo_id);
		return (0);
	}
	unlock_forks(philo);
	return (1);
}

int	start_eating(t_philo *philo, t_table *table)
{
	long int	c_time;
	long int	timestamp;

	if (philo == NULL || table == NULL)
		return (0);
	if (get_time_ms(&c_time) != 0)
	{
		unlock_forks(philo);
		return (-1);
	}
	timestamp = create_timestamp(c_time, table);
	printf("%ld %d is eating\n", timestamp, philo->philo_id);
	update_last_eat(philo);
	if (wait_action(get_time(table, 'e'), table) != 0)
	{
		unlock_forks(philo);
		return (1);
	}
	if (unlock_forks(philo) != 0)
		return (-1);
	if (get_numfinished(table) == get_philonum(table))
		return (1);
	return (0);
}

int	start_sleeping(t_philo *philo, t_table *table)
{
	long int	c_time;
	long int	timestamp;

	if (philo == NULL || table == NULL)
		return (0);
	if (get_time_ms(&c_time) != 0)
		return (-1);
	if (get_numfinished(table) == get_philonum(table))
		return (1);
	timestamp = create_timestamp(c_time, table);
	printf("%ld %d is sleeping\n", timestamp, philo->philo_id);
	if (wait_action(get_time(table, 's'), table) != 0)
		return (1);
	return (0);
}

int	start_thinking(t_philo *philo, t_table *table)
{
	long int	c_time;
	long int	timestamp;

	if (philo == NULL || table == NULL)
		return (0);
	if (get_time_ms(&c_time) != 0)
		return (-1);
	if (get_numfinished(table) == get_philonum(table))
		return (1);
	timestamp = create_timestamp(c_time, table);
	printf("%ld %d is thinking\n", timestamp, philo->philo_id);
	return (0);
}

int	died(int philo_id, t_table *table)
{
	long int	c_time;
	long int	timestamp;

	if (table == NULL)
		return (-1);
	if (get_time_ms(&c_time) != 0)
		return (-1);
	if (get_numfinished(table) != get_philonum(table))
	{
		switch_allalive(table);
		timestamp = create_timestamp(c_time, table);
		printf("%ld %d died\n", timestamp, philo_id);
	}
	return (0);
}
