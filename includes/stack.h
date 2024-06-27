/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:08:49 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/27 10:09:21 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_H
# define PS_STACK_H

#include "../libft/libft.h"

/*+------------------------------------------------------------+*/
//	STRUCT
/*+------------------------------------------------------------+*/

typedef struct	s_ps_node
{
	int					value;
	struct s_ps_node	*prev;
	struct s_ps_node	*next;
}	t_ps_node;

typedef struct s_ps_stack
{
	size_t		size;
	t_ps_node	*head;
	t_ps_node	*tail;
}	t_ps_stack;

typedef enum e_ps_action
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
} e_ps_action;


/*+------------------------------------------------------------+*/
//	NODE
/*+------------------------------------------------------------+*/

t_ps_node	*ps_node_init(int value);
void		ps_node_link_bidirection(
				t_ps_node *node,
				t_ps_node *prev,
				t_ps_node *next);

void		ps_node_link(
				t_ps_node *node,
				t_ps_node *to_link,
				int is_linking_next);

/*+------------------------------------------------------------+*/
//	STACK
/*+------------------------------------------------------------+*/

t_ps_stack	ps_stack_init(void);
int 		ps_stack_free(t_ps_stack *stack);
int			ps_stack_push(
				t_ps_stack *stack,
				t_ps_node *to_push);

/*+------------------------------------------------------------+*/
//	STACK ACTIONS
/*+------------------------------------------------------------+*/

int			ps_swap(t_ps_stack *stack);
int			ps_rotate(t_ps_stack *stack);
int			ps_rrotate(t_ps_stack *stack);
int			ps_push(t_ps_stack *from, t_ps_stack *to);
int			ps_swap2(t_ps_stack *a, t_ps_stack *b);
int			ps_rotate2(t_ps_stack *a, t_ps_stack *b);

/*+------------------------------------------------------------+*/
//	DEBUG
/*+------------------------------------------------------------+*/

void		ft_debug_print_stack(t_ps_stack *stack);
void		ft_debug_print_stacks(
				t_ps_stack *stack_a,
				t_ps_stack *stack_b );
#endif