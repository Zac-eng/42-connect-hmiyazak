/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:39:31 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/04/28 22:11:27 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_times(int argc, char **argv, long int *vars);
static int	create_table(int argc, char **argv, t_table *table);
static int	allocate_philos(t_table *table);
static void	free_philos(t_philo *philos, int philo_num);

int	main(int argc, char *argv[])
{
	t_table	table;

	if (create_table(argc, argv, &table) < 0)
		return (0);
	if (table.philo_num == 1)
	{
		usleep(table.time_d_e_s[0] * 1000);
		died(1, &table);
	}
	else if (allocate_philos(&table) != 0)
		;
	else if (philo_simulation(&table) == 0)
		join_philos(table.philos, table.philo_num);
	destruct_mutexes(table.forks, table.philo_num);
	pthread_mutex_destroy(&table.alive_mutex);
	return (0);
}
__attribute((destructor)) static void destructor()
{
    system("leaks -q philo");
}

static int	get_times(int argc, char **argv, long int *vars)
{
	if (argv == NULL || vars == NULL)
		return (-1);
	if (argc != 5 && argc != 6)
		return (-1);
	vars[0] = (long int)pos_atoi(argv[2]);
	vars[1] = (long int)pos_atoi(argv[3]);
	vars[2] = (long int)pos_atoi(argv[4]);
	if (vars[0] < 0 || vars[1] < 0 || vars[2] < 0)
		return (-1);
	return (0);
}

static int	create_table(int argc, char **argv, t_table *table)
{
	if (argv == NULL || table == NULL || (argc != 5 && argc != 6))
		return (-1);
	table->all_alive = 1;
	table->philo_num = pos_atoi(argv[1]);
	if (table->philo_num < 0)
		return (-1);
	if (get_times(argc, argv, &table->time_d_e_s[0]) != 0)
		return (-1);
	if (get_time_ms(&(table->start_time)) != 0)
		return (-1);
	if (argc == 6)
	{
		table->num_eat = pos_atoi(argv[5]);
		if (table->num_eat < 0)
			return (-1);
	}
	if (argc == 5)
		table->num_eat = -1;
	if (pthread_mutex_init(&(table->alive_mutex), NULL) != 0)
		return (-1);
	table->forks = create_forks(table->philo_num);
	if (table->forks == NULL)
		return (pthread_mutex_destroy(&(table->alive_mutex)) * 0 - 1);
	return (0);
}

static int	allocate_philos(t_table *table)
{
	int	iter;

	iter = 0;
	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->philo_num);
	if (table->philos == NULL)
		return (-1);
	while (iter < table->philo_num)
	{
		table->philos[iter].table = table;
		table->philos[iter].where = (t_thread *)malloc(sizeof(t_thread));
		if (table->philos[iter].where == NULL)
		{
			free_philos(table->philos, iter);
			return (-1);
		}
		iter += 1;
	}
	return (0);
}

static void	free_philos(t_philo *philos, int philo_num)
{
	int	iter;

	iter = 0;
	while (iter < philo_num)
	{
		free(philos[iter].where);
		iter += 1;
	}
	free(philos);
}
