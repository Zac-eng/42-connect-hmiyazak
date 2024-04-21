/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:39:25 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/11/27 14:06:01 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <float.h>
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
	double		last_eat;
}	t_philo;

typedef struct s_table {
	int		philo_num;
	double	time_d_e_s[3];
	int		num_eat;
	int		all_alive;
	t_mutex	alive_mutex;
	t_philo	*philos;
	t_mutex	*forks;
	double	start_time;
}	t_table;

int			philo_simulation(t_table *table);
t_mutex		*create_forks(int philo_num);
void		*destruct_mutexes(t_mutex *mutexes, int mutex_num);
int			pos_atoi(char *str);
void		join_philos(t_philo *philos, int philo_num);
int			get_time_ms(double *time);
double		create_timestamp(double c_time, t_table *table);
int			clean_wait(double not_eat, t_table *table, char *action);
int			lock_forks(t_philo *philo);
int			unlock_forks(t_philo *philo);
int			take_fork(t_philo *philo, t_table *table);
int			start_eating(t_philo *philo, t_table *table);
int			start_sleeping(t_philo *philo, t_table *table);
int			start_thinking(t_philo *philo, t_table *table);
int			died(int philo_id, t_table *table);

#endif
