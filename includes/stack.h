/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:08:49 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/03 00:33:16 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_H
# define PS_STACK_H

#include "../libft/libft.h"
/*+------------------------------------------------------------+*/
//	STRUCT
/*+------------------------------------------------------------+*/

typedef struct	s_node
{
	int 			value;
	int				in_pair;
	struct	s_node *next;
	struct	s_node *prev;
}	t_index_node;


typedef struct s_stack
{
	int				size;
	int				pairs;
	t_index_node	*top;
	t_index_node	*bot;
}	t_stack;

/*+------------------------------------------------------------+*/
//	INDEX
/*+------------------------------------------------------------+*/

t_index_node	*ps_node_init(int value);

/*+------------------------------------------------------------+*/
//	STACK
/*+------------------------------------------------------------+*/

t_stack	ps_stack_init(int size);

void	ps_stack_push(t_stack *stack, t_index_node *to_push);

t_index_node *ps_stack_pop(t_stack *stack);

void ps_stack_free(t_stack *stack);

/*+------------------------------------------------------------+*/
//	DEBUG
/*+------------------------------------------------------------+*/

void	ft_debug_print_stack_cluster(t_stack *stack);
void	ft_debug_print_stacks(t_stack *stack_a, t_stack *stack_b);

#endif