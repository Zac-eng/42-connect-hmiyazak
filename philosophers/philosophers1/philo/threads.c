/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:29:27 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/11/06 21:35:54 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_t	**create_philo_threads(int philo_num)
{
	pthread_t	**threads;
	int			iter;

	threads = (pthread_t **)malloc(sizeof(pthread_t *) * philo_num);
	if (threads == NULL)
		return (NULL);
	while (iter < philo_num)
	{
		pthread_create(threads[iter], NULL);
		if (threads[iter] == NULL)
			return (destruct_threads(threads, iter));
		iter += 1;
	}
	return (threads);
}

void	*destruct_threads(pthread_t **threads, int thread_num)
{
	int	iter;

	while (iter < thread_num)
	{
		pthread_exit(threads[iter]);
		iter += 1;
	}
	free(threads);
	return (NULL);
}
