/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:39:25 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/05/02 15:42:12 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

typedef pthread_t		t_thread;
typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_time;
typedef struct s_table	t_table;

typedef struct s_philo {
	int			philo_id;
	t_table		*table;
	t_thread	*where;
	t_mutex		last_eat_mutex;
	long int	last_eat;
}	t_philo;

typedef struct s_table {
	int			philo_num;
	long int	time_d_e_s[3];
	t_mutex		time_mutex;
	int			num_eat;
	t_mutex		num_eat_mutex;
	int			all_alive;
	t_mutex		alive_mutex;
	t_philo		*philos;
	t_mutex		*forks;
	long int	start_time;
	t_mutex		start_time_mutex;
}	t_table;


#endif
