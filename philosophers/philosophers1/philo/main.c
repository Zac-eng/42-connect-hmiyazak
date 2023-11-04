/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:39:31 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/11/04 15:39:48 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	int	philo_num;
	int	time_d_e_s[3];

	if (create_vars(argc, &argv[0], &time_d_e_s[0]) != 0)
		return (0);
	// create_philo_threads(philo_num);
	return (0);
}

static int	create_vars(int argc, char **argv, int *vars)
{
	if (argv == NULL || vars == NULL)
		return (-1);
	vars[0] = ft_atoi();
	return (0);
}
