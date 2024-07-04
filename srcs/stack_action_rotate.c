/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:12:55 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/03 16:44:29 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

/**
 * shift up, the top becomes the head
 * Trên xuống dưới
*/
int ps_rotate(t_stack *stack)
{
	if (stack->top)
		printf("rotate: %d\n", stack->top->value);
	t_index_node *tail_node;
	t_index_node *prev_node;

	if (stack->size < 2 || !stack->top)
		return (0);
	tail_node = stack->top;
	prev_node = tail_node->prev;
	// Unlink the top node
	prev_node->next = NULL;
	stack->top = prev_node;
	// Move the top node to the front (head)
	tail_node->prev = NULL;
	tail_node->next = stack->bot;
	stack->bot->prev = tail_node;
	stack->bot = tail_node;
	return (1);
}

static int ps_rotate_no_print(t_stack *stack)
{
	t_index_node *tail_node;
	t_index_node *prev_node;

	if (stack->size < 2 || !stack->top)
		return (0);
	tail_node = stack->top;
	prev_node = tail_node->prev;
	// Unlink the top node
	prev_node->next = NULL;
	stack->top = prev_node;
	// Move the top node to the front (head)
	tail_node->prev = NULL;
	tail_node->next = stack->bot;
	stack->bot->prev = tail_node;
	stack->bot = tail_node;
	return (1);
}

int	ps_rotate2(t_stack *a, t_stack *b)
{
	printf("rr\n");
	int	res;

	res = 1;
	if (!ps_rotate_no_print(a))
		res = 0;
	if (!ps_rotate_no_print(b))
		res = 0;
	return (res);
}