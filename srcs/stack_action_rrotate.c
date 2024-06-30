/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_rrotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:13:32 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/01 00:09:55 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

/**
 * shift down, the head becomes the tail
 * Dưới lên trên
*/
inline int ps_rrotate(t_ps_stack *stack)
{
	printf("rrotate: %d\n", stack->tail->value);
	t_ps_node	*head_node;
	t_ps_node	*next_node;

	if (stack->size < 2 || !stack->tail)
		return (0);
	head_node = stack->head;
	next_node = head_node->next;
	// Unlink the head node
	next_node->prev = NULL;
	stack->head = next_node;
	// Move the head node to the end (tail)
	head_node->next = NULL;
	head_node->prev = stack->tail;
	stack->tail->next = head_node;
	stack->tail = head_node;
	return (1);
}

inline int	ps_rrotate2(t_ps_stack *a, t_ps_stack *b)
{
	int	res;

	res = 1;
	if (!ps_rrotate(a))
		res = 0;
	if (!ps_rrotate(b))
		res = 0;
	return (res);
}