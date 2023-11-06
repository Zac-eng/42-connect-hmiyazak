/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:08:16 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/11/06 21:57:32 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	set_args(t_arg *args, int philo_num, int *time_d_e_s, int num_eat);
t_mutex		**create_mutexes(int philo_num);
void		destruct_mutexes(t_mutex **mutexes, int mutex_num);

void	philo(int philo_num, int *time_d_e_s, int num_eat)
{
	int			iter;
	t_mutex		**mutexes;
	pthread_t	**threads;
	t_arg		args;

	iter = 0;
	mutexes = create_mutexes(philo_num);
	if (mutexes == NULL)
		return ;
	threads = (pthread_t **)malloc(sizeof(pthread_t *) * philo_num);
	if (threads == NULL)
		return ;
	if (set_args(&args, philo_num, time_d_e_s, num_eat) != 0)
		return ;
	args->mutexes = mutexes;
	while (iter < philo_num)
	{
		args->philo_id = iter + 1;
		if (pthread_create(threads[iter], NULL, philo_action, args) < 0)
			return (destruct_mutexes(mutexes, philo_num));
		iter += 1;
	}
	return (destruct_mutexes(mutexes, philo_num));
}

t_mutex	**create_mutexes(int philo_num)
{
	t_mutex	**mutexes;
	int		iter;

	iter = 0;
	mutexes = (t_mutex **)malloc(sizeof(t_mutex *) * philo_num);
	if (mutexes == NULL)
		return (NULL);
	while (iter < philo_num)
	{
		if (pthread_mutex_init(mutexes[iter], NULL) != 0)
		{
			destruct_mutexes(mutexes, iter);
			return (NULL);
		}
		iter += 1;
	}
	return (mutexes);
}

void	destruct_mutexes(t_mutex **mutexes, int mutex_num)
{
	int	iter;

	iter = 0;
	while (iter < mutex_num)
	{
		pthread_mutex_destroy(mutexes[iter]);
		iter += 1;
	}
	free(mutexes);
}

static int	set_args(t_arg *args, int philo_num, int *time_d_e_s, int num_eat)
{
	if (args == NULL || time_d_e_s == NULL)
		return (-1);
	args->philo_num = philo_num;
	args->time_d_e_s[0] = time_d_e_s[0];
	args->time_d_e_s[1] = time_d_e_s[1];
	args->time_d_e_s[2] = time_d_e_s[2];
	args->num_eat = num_eat;
	return (0);
}
