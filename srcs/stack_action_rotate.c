/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:12:55 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/01 00:09:58 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

/**
 * shift up, the tail becomes the head
 * Trên xuống dưới
*/
inline int ps_rotate(t_ps_stack *stack)
{
	printf("rotate: %d\n", stack->tail->value);
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

inline int	ps_rotate2(t_ps_stack *a, t_ps_stack *b)
{
	int	res;

	res = 1;
	if (!ps_rotate(a))
		res = 0;
	if (!ps_rotate(b))
		res = 0;
	return (res);
}