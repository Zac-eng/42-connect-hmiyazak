/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_allalive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:20:02 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/04/21 18:59:08 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_allalive(t_table *table)
{
	int	all_alive;

	if (pthread_mutex_lock(&table->alive_mutex) == 0)
	{
		all_alive = table->all_alive;
		pthread_mutex_unlock(&table->alive_mutex);
		return (all_alive);
	}
	else
		return (-1);
}

void	switch_allalive(t_table *table)
{
	if (pthread_mutex_lock(&table->alive_mutex) == 0)
	{
		if (table->all_alive == 1)
			table->all_alive = 0;
		pthread_mutex_unlock(&table->alive_mutex);
	}
}
