/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:47:16 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/14 12:20:05 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"
#include "../includes/push_swap.h"

static inline void	a2b_push_rotate(
	t_chunk *chunk,
	t_stack *a,
	t_stack *b
)
{
	if (index_in_range(a->top->index, chunk->min, (chunk->median)))
	{
		ps_stack_action("pb", a, b);
		if (b->size >= 2)
			ps_stack_action("rb", a, b);
	}
	else if (index_in_range(a->top->index, (chunk->median + 1), chunk->max))
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

	chunk = a2b_chunk_init(data, a);
	while (a->size > 3)
	{
		if (chunk_check_index_exist(&chunk, a))
		{
			a2b_push_rotate(&chunk, a, b);
			a2b_update_chunk(data, &chunk, a);
		}
	}
	if (!ps_stack_is_sorted(a))
		ps_sort3(a, b);
}

/**
 * Second phase of pushing A to B
 * Description:
 * - u_top represents unordered numbers at the top
 * - u_bot represents unordered numbers at the bottom
 */
void	ps_b2a(t_stack *a, t_stack *b)
{
	int	highest;
	int	u_top;
	int	u_bot;

	u_top = 0;
	u_bot = 0;
	highest = b->size - 1;
	while (b->size || u_bot > 0 || u_top > 0)
	{
		if (a_contains_largest_sort_a(a, &u_top, &u_bot, highest))
			highest--;
		else if (b->size && b->top->index == highest)
		{
			reorder_before_push(a, b, &u_top, &u_bot);
			highest--;
		}
		else if (push_almost_highest(a, b, &u_top, &u_bot))
			continue ;
		else if (rotate_b(a, b, highest))
			continue ;
		else
			highest--;
	}
}

void	ps_sort(t_data *data, t_stack *a, t_stack *b)
{
	if (ps_stack_is_sorted(a))
		return ;
	if (data->total_amt == 2)
	{
		if (a->top->index > a->top->prev->index)
			ps_stack_action("sa", a, b);
	}
	else if (data->total_amt > 3)
	{
		ps_a2b(data, a, b);
		ps_b2a(a, b);
	}
	else if (data->total_amt == 3)
		ps_sort3(a, b);
}
