/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:39:31 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/11/04 16:04:51 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_vars(int argc, char **argv, int *vars);

int	main(int argc, char *argv[])
{
	int	philo_num;
	int	time_d_e_s[3];

	if (create_vars(argc, &argv[0], &time_d_e_s[0]) != 0)
		return (0);
	philo_num = pos_atoi(argv[4]);
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", time_d_e_s[i]);
	}
	// create_philo_threads(philo_num);
	return (0);
}

static int	create_vars(int argc, char **argv, int *vars)
{
	if (argv == NULL || vars == NULL)
		return (-1);
	if (argc != 5)
		return (-1);
	vars[0] = pos_atoi(argv[1]);
	vars[1] = pos_atoi(argv[2]);
	vars[2] = pos_atoi(argv[3]);
	if (vars[0] < 0 || vars[1] < 0 || vars[2] < 0)
		return (-1);
	return (0);
}
