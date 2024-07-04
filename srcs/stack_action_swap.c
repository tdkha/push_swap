/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:12:38 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/03 16:44:07 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	ps_swap(t_stack *stack)
{
	if(stack->top)
		printf("swap: %d\n", stack->top->value);
	t_index_node	*tail_node;
	t_index_node	*prev_node;
	t_index_node	*prev_prev_node;

	if (stack->size < 2 || !stack->top)
		return (0);
	tail_node = stack->top;
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
		stack->bot = tail_node;

	stack->top = prev_node;
	return (1);
}

int	ps_swap2(t_stack *a, t_stack *b)
{
	int	res;

	res = 1;
	if (!ps_swap(a))
		res = 0;
	if (!ps_swap(b))
		res = 0;
	return (res);
}
