/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:57:35 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/11/06 22:00:40 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	philo_action(t_arg *args)
{
	int	iter;

	iter = 0;
	if (args->num_eat == -1)
	{
		while (1)
			philo_cycle(args);
	}
	else
	{
		while (iter < args->num_eat)
		{
			philo_cycle(args);
			iter += 1;
		}
	}
}

static void	philo_cycle(t_arg *args)
{
	int	philo_id;
	int	current_time;

	philo_id = args->philo_id;
	if (pthread_mutex_lock(args->mutexes[philo_id - 1]) != 0)
		return ;
	if (pthread_mutex_lock(args->mutexes[philo_id]) != 0)
		return ;
	current_time = gettimeofday();
	take_fork(current_time, args->philo_id);
}
