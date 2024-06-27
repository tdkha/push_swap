/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_rrotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:13:32 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/27 09:44:20 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

/**
 * shift down, the tail becomes the head
*/
int ps_rrotate(t_ps_stack *stack)
{
	t_ps_node *tail_node;
	t_ps_node *prev_node;

	if (stack->size < 2 || !stack->tail)
		return (0);
	tail_node = stack->tail;
	prev_node = tail_node->prev;
	// Unlink the tail node
	prev_node->next = NULL;
	stack->tail = prev_node;
	// Move the tail node to the front (head)
	tail_node->prev = NULL;
	tail_node->next = stack->head;
	stack->head->prev = tail_node;
	stack->head = tail_node;
	return (1);
}

int	ps_rrotate2(t_ps_stack *a, t_ps_stack *b)
{
	
}