/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:22:02 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/05 22:33:25 by hmiyazak         ###   ########.fr       */
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
	int		max_size;
}	t_stack;

t_node	*create_node(int argc, char **argv);
t_node	*generate_element(t_node *previous, int node_content);
t_stack	*create_stack(int argc, char **argv);
void	create_input_list(int argc, char **argv, int *foundation);
void	compress_list(int list_size, int *to_be_compressed);
int		swap_element(t_node *first, t_node *second);
int		push_a(t_node *a_top, t_node *b_top);
int		push_b(t_node *a_top, t_node *b_top);
int		swap(t_node *node_top);
int		swap_s(t_node *a_top, t_node *b_top);
int		rotate(t_node *node_top);
int		rotate_r(t_node *a_top, t_node *b_top);
int		rotate_a(t_node *a_top);
int		rotate_b(t_node *b_top);
int		atoi_or_exit(char *should_num);
int		ft_isspace(char c);

#endif
