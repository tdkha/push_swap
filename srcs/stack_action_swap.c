/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:12:38 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/02 13:41:33 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

inline int	ps_swap(t_ps_stack *stack)
{
	if (stack->tail)
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

static inline int	ps_swap_no_print(t_ps_stack *stack)
{
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

	printf("ss\n");
	res = 1;
	ps_swap_no_print(a);
	ps_swap_no_print(b);
	return (res);
}

int ps_swap_special(t_ps_stack *a, t_ps_stack *b)
{
	t_ps_node *b_tail_node;
	t_ps_node *b_adj_tail_node;

	b_tail_node = b->tail;
	if (!b_tail_node)
	{
		return ps_swap(a);
	}
	b_adj_tail_node = b->tail->prev;
	if (!b_adj_tail_node)
	{
		return ps_swap(a);
	}
	if (b_tail_node->value < b_adj_tail_node->value)
	{
		return ps_swap2(a, b);
	}
	return ps_swap(a);
}
