/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:56:24 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/04/21 18:51:35 by hmiyazak         ###   ########.fr       */
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
	if (c_time - philo->last_eat < table->time_d_e_s[0] && \
									get_allalive(table) == 1)
	{
		printf("%f %d has taken a fork\n", timestamp, philo->philo_id);
		return (0);
	}
	unlock_forks(philo);
	if (get_allalive(table) == 1)
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
	if (get_allalive(table) == 0)
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
	else if (get_allalive(table) == 0)
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
	if (get_allalive(table) == 1)
	{
		switch_allalive(table);
		timestamp = create_timestamp(c_time, table);
		printf("%f %d died\n", timestamp, philo_id);
	}
	return (0);
}
