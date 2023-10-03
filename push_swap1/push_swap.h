/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:22:02 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/03 14:54:11 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	struct s_stack	*previous;
	int				body;
	struct s_stack	*next;
}	t_stack;

t_stack	*create_stack(int argc, char **argv);
t_stack	*generate_element(t_stack *previous, int stack_content);
int		swap_element(t_stack *first, t_stack *second);
int		push_a(t_stack *a_top, t_stack *b_top);
int		push_b(t_stack *a_top, t_stack *b_top);
int		swap(t_stack *stack_top);
int		swap_s(t_stack *a_top, t_stack *b_top);
int		rotate(t_stack *stack_top);
int		rotate_r(t_stack *a_top, t_stack *b_top);


#endif
