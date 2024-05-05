/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:39:31 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/05/05 18:54:53 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	allocate_philos(t_table *table);
static void	free_philos(t_philo *philos, int philo_num);

int	main(int argc, char *argv[])
{
	t_table	table;

	if (create_table(argc, argv, &table) < 0)
		return (0);
	if (table.philo_num == 1)
	{
		wait_action(table.time_d_e_s[0], &table);
		died(1, &table);
	}
	else if (allocate_philos(&table) != 0)
		;
	else if (philo_simulation(&table) == 0)
		join_philos(table.philos, get_philonum(&table));
	switch_allalive(&table);
	destruct_mutexes(table.forks, table.philo_num);
	destroy_table_mutexes(&table);
	return (0);
}
// __attribute((destructor)) static void destructor()
// {
//     system("leaks -q philo");
// }

static int	allocate_philos(t_table *table)
{
	int	iter;

	iter = 0;
	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->philo_num);
	if (table->philos == NULL)
		return (-1);
	while (iter < get_philonum(table))
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
