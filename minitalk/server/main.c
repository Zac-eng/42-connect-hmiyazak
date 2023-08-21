/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:38:24 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/07/22 17:57:22 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	print_pid(void);
static void	signal_handler(int code);

int	main(void)
{
	print_pid();
	pause();
	signal(SIGUSR1, signal_handler);
}

static void	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
}

static void	signal_handler(int code)
{
	ft_printf("signal received %d", code);
	signal(SIGUSR1, signal_handler);
}

// static int	signal_handler2(int code)
// {
// 	ft_printf()
// }
