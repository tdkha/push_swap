/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_rrotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:13:32 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/13 23:34:02 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

/**
 * shift down, the head becomes the top
 * Dưới lên trên
*/
int	ps_rrotate(t_stack *stack)
{
	t_index_node	*head_node;
	t_index_node	*next_node;

	if (stack->size < 2 || !stack->top)
		return (0);
	head_node = stack->bot;
	next_node = head_node->next;
	next_node->prev = NULL;
	stack->bot = next_node;
	head_node->next = NULL;
	head_node->prev = stack->top;
	stack->top->next = head_node;
	stack->top = head_node;
	return (1);
}

int	ps_rrotate2(t_stack *a, t_stack *b)
{
	int	res;

	res = 1;
	if (!ps_rrotate(a))
		res = 0;
	if (!ps_rrotate(b))
		res = 0;
	return (res);
}
