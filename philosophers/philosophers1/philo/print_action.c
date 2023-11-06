/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:56:24 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/11/06 21:35:53 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(int timestamp, int philo_num)
{
	return (printf("%d %d has taken a fork", timestamp, philo_num));
}

int	start_eating(int timestamp, int philo_num)
{
	return (printf("%d %d is eating", timestamp, philo_num));
}

int	start_sleeping(int timestamp, int philo_num)
{
	return (printf("%d %d is sleeping", timestamp, philo_num));
}

int	start_thinking(int timestamp, int philo_num)
{
	return (printf("%d %d is thinking", timestamp, philo_num));
}

int	died(int timestamp, int philo_num)
{
	return (printf("%d %d died", timestamp, philo_num));
}
