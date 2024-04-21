/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_wait.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:18:02 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/04/21 18:35:08 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	wait_action(double wait_time_ms, t_table *table);
static int	set_action(char *action, double *set_time, double *time_d_e_s);
static int	ft_strcmp(char *lhs, char *rhs);

int	clean_wait(double not_eat, t_table *table, char *action)
{
	double	action_time;
	double	die_time;

	die_time = table->time_d_e_s[0];
	if (set_action(action, &action_time, &(table->time_d_e_s[0])) != 0)
		return (-1);
	if (not_eat + action_time < table->time_d_e_s[0])
		return (wait_action(action_time, table));
	else
		return (wait_action(table->time_d_e_s[0] - not_eat, table) + 1);
}

static int	wait_action(double wait_time_ms, t_table *table)
{
	double	action_start;
	double	time;
	int		iter;

	iter = 0;
	get_time_ms(&action_start);
	while (iter < 8)
	{
		if (get_allalive(table) == 1)
			usleep(wait_time_ms * 100);
		else
			return (1);
		iter += 1;
	}
	get_time_ms(&time);
	if (action_start + wait_time_ms - time > 0)
		usleep((action_start + wait_time_ms - time) * 1000);
	return (0);
}

static int	set_action(char *action, double *set_time, double *time_d_e_s)
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
