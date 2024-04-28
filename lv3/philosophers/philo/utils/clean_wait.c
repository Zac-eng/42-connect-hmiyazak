/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_wait.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:18:02 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/04/28 21:51:10 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	wait_action(long int wait_time_ms, t_table *table);
static int	set_action(char *action, long int *set_time, long int *time_d_e_s);
static int	ft_strcmp(char *lhs, char *rhs);

int	clean_wait(long int not_eat, t_table *table, char *action)
{
	long int	action_time;
	long int	die_time;

	die_time = table->time_d_e_s[0];
	if (set_action(action, &action_time, &(table->time_d_e_s[0])) != 0)
		return (-1);
	if (not_eat + action_time < table->time_d_e_s[0])
		return (wait_action(action_time, table));
	else
		return (wait_action(table->time_d_e_s[0] - not_eat, table) + 1);
}

static int	wait_action(long int wait_time_ms, t_table *table)
{
	long int	action_start;
	long int	time;
	long int	waited;

	waited = 0;
	get_time_ms(&action_start);
	while (waited + 45 < wait_time_ms)
	{
		if (get_allalive(table) == 1)
			usleep(10000);
		else
			return (1);
		waited += 10;
	}
	get_time_ms(&time);
	while (time < action_start + wait_time_ms)
		get_time_ms(&time);
	return (0);
}

static int	set_action(char *action, long int *set_time, long int *time_d_e_s)
{
	if (ft_strcmp(action, "eat") == 1)
	{
		*set_time = time_d_e_s[1];
		return (0);
	}
	else if (ft_strcmp(action, "sleep") == 1)
	{
		*set_time = time_d_e_s[2];
		return (0);
	}
	else
		return (-1);
}

static int	ft_strcmp(char *lhs, char *rhs)
{
	if (lhs == NULL || rhs == NULL)
		return (-1);
	while (*lhs != '\0' && *rhs != '\0')
	{
		if (*lhs != *rhs)
			return (0);
		lhs += 1;
		rhs += 1;
	}
	if (*lhs != '\0' || *rhs != '\0')
		return (0);
	return (1);
}
