/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:17:59 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/30 19:14:06 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

/**
 * Initialize a struct <t_ps_stack>
 */
t_ps_stack	ps_stack_init(void)
{
	t_ps_stack	res;

	res.size = 0;
	res.cluster_count = 0;
	res.head = NULL;
	res.tail = NULL;
	return (res);
}

/**
 * Push new <node> to the top of the stack
 */
int	ps_stack_push(t_ps_stack *stack, t_ps_node *to_push)
{
	if (!to_push)
		return(0);
	if (!stack->head)
	{
		stack->head = to_push;
		stack->tail = to_push;
	}
	else
	{
		stack->tail->next = to_push;
		to_push->prev = stack->tail;
		stack->tail = to_push;
	}
	stack->size++;
	return (1);
}

/**
 * Free memory regarding a struct <t_ps_stack>
 */
int ps_stack_free(t_ps_stack *stack)
{
	t_ps_node	*cur_node;
	t_ps_node	*tmp_node;

	cur_node = stack->head;
	while (cur_node)
	{
		tmp_node = cur_node->next;
		free(cur_node);
		cur_node = tmp_node;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (1);
}

