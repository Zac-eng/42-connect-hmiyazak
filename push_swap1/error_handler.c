/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:18:49 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/09/10 14:31:30 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_int(char charactor);

int	check_arg(char *argument)
{
	while (*argument)
	{
		if (is_int(*argument) == 1)
			argument += 1;
		else
			return (-1);
	}
	return (0);
}

static int	is_int(char charactor)
{
	if ('0' < charactor && charactor < '9')
		return (1);
	else
		return (-1);
}
