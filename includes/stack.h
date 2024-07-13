/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:08:49 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/13 14:35:49 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_H
# define PS_STACK_H

#include "../libft/libft.h"
/*+------------------------------------------------------------+*/
//	STRUCT
/*+------------------------------------------------------------+*/

/**
 * @param amt_per_chunk : {int} the avergae amount of elements inside a pair (the last one is a bit different)
 */
typedef	struct s_data
{
	int 	ac;
	char	**av;
	int		total_amt;
	int 	amt_per_chunk;
	int 	max_chunks;
}	t_data;

typedef struct	s_node
{
	int 			index;
	struct	s_node *next;
	struct	s_node *prev;
}	t_index_node;


typedef struct s_stack
{
	int				size;
	t_index_node	*top;
	t_index_node	*bot;
}	t_stack;

typedef struct	s_chunk
{
	int	max;
	int	median;
	int	min;
}	t_chunk;

/*+------------------------------------------------------------+*/
//	INDEX
/*+------------------------------------------------------------+*/

t_index_node	*ps_node_init(int index);

/*+------------------------------------------------------------+*/
//	STACK UTILS
/*+------------------------------------------------------------+*/

int		ps_stack_is_sorted(t_stack  *stack);

/*+------------------------------------------------------------+*/
//	STACK ACTIONS
/*+------------------------------------------------------------+*/

int		ps_push(t_stack *from, t_stack *to);
int		ps_rotate(t_stack *stack);
int		ps_rrotate(t_stack *stack);
int		ps_swap(t_stack *stack);
int		ps_rotate2(t_stack *a, t_stack *b);
void	ps_stack_action(char *str, t_stack *a, t_stack *b);
/*+------------------------------------------------------------+*/
//	STACK
/*+------------------------------------------------------------+*/

t_stack	ps_stack_init(void);

void	ps_stack_push(t_stack *stack, t_index_node *to_push);

void 	ps_stack_free(t_stack *stack);

/*+------------------------------------------------------------+*/
//	DEBUG
/*+------------------------------------------------------------+*/

void	ft_debug_print_stacks(t_stack *stack_a, t_stack *stack_b);

#endif