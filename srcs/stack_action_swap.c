/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:12:38 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/01 00:05:19 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

inline int	ps_swap(t_ps_stack *stack)
{
	printf("swap: %d\n", stack->tail->value);
	t_ps_node	*tail_node;
	t_ps_node	*prev_node;
	t_ps_node	*prev_prev_node;

	if (stack->size < 2 || !stack->tail)
		return (0);
	tail_node = stack->tail;
	prev_node = tail_node->prev;
	prev_prev_node = prev_node->prev;
	// swapping tail_node and prev_node
	prev_node->next = tail_node->next;
	// if (prev_node->next)
	// 	prev_node->next->prev = prev_node;

	prev_node->prev = tail_node;
	tail_node->next = prev_node;
	tail_node->prev = prev_prev_node;
	if (prev_prev_node)
		prev_prev_node->next = tail_node;
	else
		stack->head = tail_node;

	stack->tail = prev_node;
	return (1);
}

inline int	ps_swap2(t_ps_stack *a, t_ps_stack *b)
{
	int	res;

	res = 1;
	if (!ps_swap(a))
		res = 0;
	if (!ps_swap(b))
		res = 0;
	return (res);
}
