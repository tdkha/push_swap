/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_b2a_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:14:54 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/09 19:03:22 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"


int	distance_from_top(
	int to_find,
	t_stack *b)
{
	t_index_node	*node;
	int				dist;

	node = b->top;
	dist = 0;
	while (node)
	{
		if (node->index == to_find)
		{
			break;
		}
		dist++;
		node = node->prev;
	}
	return (dist);
}

int	distance_from_bot(
	int to_find,
	t_stack *b)
{
	t_index_node	*node;
	int				dist;

	node = b->bot;
	dist = 0;
	while (node)
	{
		if (node->index == to_find)
		{
			break;
		}
		dist++;
		node = node->next;
	}
	return (dist);
}