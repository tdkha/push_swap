/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:12:55 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/26 16:31:56 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"


int	ft_rotate(t_ps_stack *stack)
{
	t_ps_node	*tail_node;
	t_ps_node	*prev_node;
	t_ps_node	*prev_prev_node;
	
	if (stack->size < 2 || !stack->tail)
		return (0);
	tail_node = stack->tail;
	prev_node = tail_node->prev;
	prev_prev_node = prev_node->prev;
	prev_node->prev = tail_node;
	tail_node->next = prev_node;
	prev_prev_node->next = tail_node;
	tail_node->prev = prev_prev_node;
	prev_node->next = NULL;
	stack->tail = prev_node;
	return (1);
}

int	ft_rotate2(t_ps_stack *a, t_ps_stack *b)
{
	if (!ft_rotate(a))
		return (0);
	if (!ft_rotate(b))
		return (0);
	return (1);
}