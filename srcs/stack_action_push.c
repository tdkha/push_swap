/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:47:21 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/01 00:04:28 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

inline int	ps_push(t_ps_stack *from, t_ps_stack *to)
{
	printf("push %d\n", from->tail->value);
	t_ps_node	*to_add_node;

	if (from->size < 1 || !from->tail)
		return (0);
	to_add_node = from->tail;
	if (from->tail->prev)
	{
		from->tail = from->tail->prev;
		from->tail->next = NULL;
	}
	else
	{
		from->head = NULL;
		from->tail = NULL;
	}
	to_add_node->prev = NULL;
	from->size--;
	ps_stack_push(to, to_add_node);
	return (1);
}
