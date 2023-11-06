/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:39:25 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/11/06 21:57:12 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_arg {
	int		philo_num;
	int		time_d_e_s[3];
	int		num_eat;
	int		philo_id;
	t_mutex	**mutexes;
}	t_arg;

void	philo(int philo_num, int *time_d_e_s, int num_eat);
int		pos_atoi(char *str);
int		take_fork(int timestamp, int philo_num);
int		start_eating(int timestamp, int philo_num);
int		start_sleeping(int timestamp, int philo_num);
int		start_thinking(int timestamp, int philo_num);
int		died(int timestamp, int philo_num);

#endif
