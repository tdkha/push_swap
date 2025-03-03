/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:17:59 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/14 08:39:58 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"
#include "../includes/push_swap.h"

/**
 * Initialize a struct <t_stack>
 */
t_stack	ps_stack_init(void)
{
	t_stack	res;

	res.size = 0;
	res.top = NULL;
	res.bot = NULL;
	return (res);
}

/**
 * Push new <to_push> to the top of the stack
 */
void	ps_stack_push(t_stack *stack, t_index_node *to_push)
{
	if (!stack->bot)
	{
		stack->bot = to_push;
		stack->top = to_push;
	}
	else
	{
		stack->top->next = to_push;
		to_push->prev = stack->top;
		stack->top = to_push;
	}
	stack->size++;
}

/**
 * Free memory regarding a struct <t_stack>
 */
void	ps_stack_free(t_stack *stack)
{
	t_index_node	*cur_node;
	t_index_node	*tmp_node;

	cur_node = stack->bot;
	while (cur_node)
	{
		tmp_node = cur_node->next;
		free(cur_node);
		cur_node = tmp_node;
	}
	stack->bot = NULL;
	stack->top = NULL;
	stack->size = 0;
}

/**
 * Check if a stack is sorted from top down in ascending order
 */
int	ps_stack_is_sorted(t_stack *stack)
{
	t_index_node	*cur_node;

	cur_node = stack->bot;
	while (cur_node)
	{
		if (cur_node->next && cur_node->index < cur_node->next->index)
			return (0);
		cur_node = cur_node->next;
	}
	return (1);
}
