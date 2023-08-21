/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:39:07 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/07/22 18:31:35 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	check_input(int argc, void *arg_pid);
static void	send_char_sig(int pid, char charactor);

int	main(int argc, char *argv[])
{
	int	pid;

	if (check_input(argc, argv[1]) == -1)
		return (0);
	pid = ft_atoi(argv[1]);
	while (*argv[2] != '\0')
	{
		send_char_sig(pid, *argv[2]);
		argv[2] += 1;
	}
}

static int	check_input(int argc, void *arg_pid)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("the number of argument is invalid\n");
		return (-1);
	}
	pid = ft_atoi(arg_pid);
	ft_printf(":%d\n", arg_pid);
	if (pid <= 0)
	{
		ft_printf("the pid should be integer");
		return (-1);
	}
	return (0);
}

static void	send_char_sig(int pid, char charactor)
{
	ft_printf("%d: %c\n", pid, charactor);
}
