/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:47:21 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/04 11:45:57 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	ps_push(t_stack *from, t_stack *to)
{
	// if(from->top)
	// 	printf("push %d\n", from->top->value);
	t_index_node	*to_add_node;

	if (from->size < 1 || !from->top)
		return (0);
	to_add_node = from->top;
	if (from->top->prev)
	{
		from->top = from->top->prev;
		from->top->next = NULL;
	}
	else
	{
		from->bot = NULL;
		from->top = NULL;
	}
	to_add_node->prev = NULL;
	from->size--;
	ps_stack_push(to, to_add_node);
	return (1);
}
