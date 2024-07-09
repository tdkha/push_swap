/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:47:16 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/09 19:05:06 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"
#include "../includes/push_swap.h"

static inline void a2b_push_rotate(
	t_chunk *chunk,
	int offset,
	t_stack *a,
	t_stack *b
)
{
	if (index_in_range(a->top->index, chunk->min, (chunk->median - offset)))
	{
		ps_stack_action("pb", a, b);
		ps_stack_action("rb", a, b);
	}
	else if (index_in_range(a->top->index, (chunk->median + offset), chunk->max))
		ps_stack_action("pb", a, b);
	else
		ps_stack_action("ra", a, b);
}

/**
 * Phase 1 of pusing from stack a to stack b
 * Description:
 * 	(1)	Running a loop to push until there is 3 numbers left
 * 	(2)	Start from the middle chunk and then gradually extend it
 * 	(3) To scale the chunk, the <offset> is needed
 *______a) <median> is a middle point (size / 2)
 *______b) <median + offset> is a range from the second scale
 *	(4)	Update the chunk when all elements belonging to the current chunk
 *		have been pushed to B,	
 */
void	ps_a2b(t_data *data, t_stack *a, t_stack *b)
{
	t_chunk		chunk;
	int			scaler;
	int			offset;

	chunk = a2b_chunk_init(data, a);
	scaler = 0;
	offset = scaler * (data->amt_per_chunk / 2);
	while (a->size > 3)
	{
		if (chunk_check_index_exist(data, &chunk, a))
		{
			a2b_push_rotate(&chunk, offset, a, b);
		}
		else
		{
			update_chunk(data, &chunk);
			scaler++;
			offset = scaler * (data->amt_per_chunk / 2);	
			if (chunk.median - offset < 1)
				break;
		}
	}
	if (!ps_stack_is_sorted(a))
		ps_sort3(a, b);
}


void	max_to_top(
	t_chunk *chunk,
	t_stack *a,
	t_stack *b
)
{	
	int	dist_from_top;
	int	dist_from_bot;
	int	iteration;

	dist_from_top = distance_from_top(chunk->max, b);
	dist_from_bot = distance_from_bot(chunk->max, b);
	if (dist_from_top < dist_from_bot)
		iteration = dist_from_top;
	else
		iteration = dist_from_bot;
	chunk->max--;
	if (dist_from_top > dist_from_bot)
	{
		iteration++;
		while (iteration-- > 0)
			ps_stack_action("rrb", a, b);
	}
	else
	{
		while (iteration-- > 0)
			ps_stack_action("rb", a, b);
	}
	ps_stack_action("pa",a ,b);
}

void	b2a_push(
	t_chunk *chunk,
	t_stack *a,
	t_stack *b
)
{

}


void	ps_b2a(t_data *data, t_stack *a, t_stack *b)
{
	t_chunk	chunk;

	chunk.max = b->size;
	chunk.min = chunk.max - data->amt_per_chunk;
	chunk.median = (chunk.max + chunk.min) / 2;
	while (b->size)
	{
		max_to_top(&chunk, a, b);
	}
}

void	ps_sort(t_data *data, t_stack *a, t_stack *b)
{
	if (data->total_amt > 3)
	{
		ps_a2b(data, a, b);
		ps_b2a(data, a, b);
	}
	else if (data->total_amt == 3)
		ps_sort3(a, b);
}