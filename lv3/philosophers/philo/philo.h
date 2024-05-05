/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:39:25 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/05/05 23:14:10 by hmiyazak         ###   ########.fr       */
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
	int			have_eaten;
	long int	last_eat;
	t_table		*table;
	t_thread	*where;
	t_mutex		philo_mutex;
}	t_philo;

typedef struct s_table {
	int			philo_num;
	long int	time_d_e_s[3];
	t_mutex		time_mutex;
	long int	num_eat;
	t_mutex		num_eat_mutex;
	int			all_alive;
	t_mutex		alive_mutex;
	t_philo		*philos;
	t_mutex		*forks;
	long int	start_time;
	t_mutex		start_time_mutex;
}	t_table;

void		monitor(t_table *table);
int			philo_simulation(t_table *table);
int			create_table(int argc, char **argv, t_table *table);
t_mutex		*create_forks(int philo_num);
void		*destruct_mutexes(t_mutex *mutexes, int mutex_num);
int			pos_atoi(char *str);
void		join_philos(t_philo *philos, int philo_num);
int			get_time_ms(long int *time);
long int	create_timestamp(long int c_time, t_table *table);
int			wait_action(long int wait_time_ms, t_table *table);
int			lock_forks(t_philo *philo);
int			unlock_forks(t_philo *philo);
int			take_fork(t_philo *philo, t_table *table);
int			start_eating(t_philo *philo, t_table *table);
int			start_sleeping(t_philo *philo, t_table *table);
int			start_thinking(t_philo *philo, t_table *table);
int			died(int philo_id, t_table *table);
int			pos_atoi(char *str);
int			get_allalive(t_table *table);
int			get_time(t_table *table, const char which_time);
int			get_have_eaten(t_philo *philo);
long int	get_start_time(t_table *table);
long int	get_last_eat(t_philo *philo);
void		switch_allalive(t_table *table);
int			update_last_eat(t_philo *philo);
int			increment_have_eaten(t_philo *philo);

#endif
