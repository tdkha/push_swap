/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_a2b_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:15:41 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/16 09:47:08 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"

int	chunk_check_index_exist(
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
			break ;
		}
		node = node->prev;
	}
	return (exist);
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
	return (0);
}

static void	check_chunk_in_range(
	t_chunk *chunk,
	int *found_chunk_top,
	int *found_chunk_bot,
	t_index_node *node)
{
	while (node)
	{
		if (index_in_range(node->index, chunk->median, chunk->max))
			*found_chunk_top = 1;
		if (index_in_range(node->index, chunk->min, chunk->median))
			*found_chunk_bot = 1;
		node = node->prev;
	}
}

void	a2b_update_chunk(
	t_data *data,
	t_chunk *chunk,
	t_stack *a
)
{
	int				found_chunk_top;
	int				found_chunk_bot;
	t_index_node	*node;

	found_chunk_top = 0;
	found_chunk_bot = 0;
	node = a->top;
	check_chunk_in_range(chunk, &found_chunk_top, &found_chunk_bot, node);
	if (!found_chunk_top)
	{
		chunk->max += (data->amt_per_chunk / 2);
		if (chunk->max >= data->total_amt - 3)
			chunk->max = data->total_amt - 4;
	}
	if (!found_chunk_bot)
	{
		chunk->min -= (data->amt_per_chunk / 2);
		if (chunk->min < 0)
			chunk->min = 0;
	}
}

t_chunk	a2b_chunk_init(t_data *data, t_stack *a)
{
	t_chunk	chunk;

	chunk.median = (a->size - 3) / 2;
	chunk.max = chunk.median + (data->amt_per_chunk / 2);
	if (chunk.max >= data->total_amt - 3)
	{
		chunk.max = data->total_amt - 4;
	}
	chunk.min = chunk.median - (data->amt_per_chunk / 2);
	if (chunk.min < 0)
	{
		chunk.min = 0;
	}
	if (index_in_range(chunk.min, data->ac - 3, data->ac - 1))
	{
		chunk.max = data->total_amt - 4;
	}
	return (chunk);
}
