/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:20:14 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/03 00:47:27 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	ps_stack_is_sorted(t_stack  *stack)
{
	t_index_node	*cur_node;

	cur_node = stack->bot;
	while (cur_node)
	{
		if (cur_node->next && cur_node->value < cur_node->next->value)
			return(0);
		cur_node= cur_node->next;
	}
	return (1);
}