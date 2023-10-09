/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:22:02 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/06 18:22:42 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	struct s_node	*previous;
	int				body;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		current_size;
	int		max_size;
}	t_stack;

t_node	*create_node(int argc, char **argv);
t_node	*generate_element(t_node *previous, int node_content);
t_stack	*create_stack(int argc, char **argv);
void	create_input_list(int argc, char **argv, int *foundation);
void	compress_list(int list_size, int *to_be_compressed);
void	push_top(t_stack *stack, int new_element);
void	push_bottom(t_stack *stack, int new_element);
int		pop_top(t_stack *stack);
int		pop_bottom(t_stack *stack);
int		atoi_or_exit(char *should_num);
int		ft_isspace(char c);

#endif
