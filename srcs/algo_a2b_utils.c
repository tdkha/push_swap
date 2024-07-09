/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_a2b_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:15:41 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/09 17:15:43 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"

int	chunk_check_index_exist(
	t_data * data,
	t_chunk *chunk,
	t_stack *a
)
{
	t_index_node	*node;
	int				exist;

	exist = 0;
	node = a->top;
	while (node)
	{
		if (node->index <= chunk->max && node->index >= chunk->min)
		{
			exist = 1;
			break;
		}
		node = node->prev;
	}
	return (exist);
}

void	update_chunk(
	t_data * data,
	t_chunk *chunk
)
{
	chunk->max += (data->amt_per_chunk /2);
	chunk->min -= (data->amt_per_chunk /2);
	if (chunk->max >= data->total_amt - 2)
		chunk->max = data->total_amt - 3;
	if (chunk->min < 1)
		chunk->min = 1;
}

int	index_in_range(
	int index,
	int min,
	int max
)
{
	if (index <= max && index >= min)
	{
		return (1);
	}
	return  (0);
}
t_chunk	a2b_chunk_init(t_data *data, t_stack *a)
{
	t_chunk	chunk;
	chunk.median = a->size / 2;
	chunk.max = chunk.median + (data->amt_per_chunk / 2);
	chunk.min = chunk.median - (data->amt_per_chunk / 2);
	return (chunk);
}