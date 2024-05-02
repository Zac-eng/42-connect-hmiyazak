/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:08:16 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/05/02 16:40:15 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_action(void *philo);
static int	philo_cycle(t_philo *philo, t_table *table);
void		join_philos(t_philo *philos, int philo_num);

int	philo_simulation(t_table *table)
{
	int		iter;
	t_philo	*actor;

	iter = 0;
	if (table == NULL || table->philos == NULL)
		return (-1);
	while (iter < table->philo_num)
	{
		actor = &(table->philos[iter]);
		actor->philo_id = iter + 1;
		actor->last_eat = table->start_time;
		if (pthread_mutex_init(&actor->last_eat_mutex, NULL) != 0)
			return (-1);
		if (pthread_create(actor->where, NULL, philo_action, actor) != 0)
		{
			switch_allalive(table);
			join_philos(table->philos, iter);
			pthread_mutex_destroy(&actor->last_eat_mutex);
			return (-1);
		}
		iter += 1;
	}
	monitor(table);
	return (0);
}

static void	*philo_action(void *philo)
{
	int			iter;
	long int	cycle;
	t_philo		*actor;
	t_table		*table;

	iter = 0;
	actor = philo;
	table = actor->table;
	cycle = get_num_eat(table);
	if (cycle < 0)
		cycle = LONG_MAX;
	while (iter < cycle)
	{
		if (philo_cycle(actor, table) == 1)
			break ;
		iter += 1;
	}
	return (NULL);
}

static int	philo_cycle(t_philo *philo, t_table *table)
{
	if (take_fork(philo, table) != 0)
		return (1);
	if (start_eating(philo, table) != 0)
		return (1);
	if (start_sleeping(philo, table) != 0)
		return (1);
	if (start_thinking(philo, table) != 0)
		return (1);
	return (0);
}

void	join_philos(t_philo *philos, int philo_num)
{
	int	iter;

	if (philos == NULL)
		return ;
	iter = 0;
	while (iter < philo_num)
	{
		if (philos[iter].where != NULL)
		{
			pthread_join(*(philos[iter].where), NULL);
			free(philos[iter].where);
		}
		iter += 1;
	}
	free(philos);
}
