/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 00:41:15 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/13 20:54:31 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"

static inline void tail_is_largest(t_stack *a, t_stack *b)
{
	ps_stack_action("ra", a, b);
	if (a->top->index > a->top->prev->index)
	{
		ps_stack_action("sa", a, b);
	}
}

static inline void mid_is_largest(t_stack *a, t_stack *b)
{
	if (a->top->index > a->bot->index)
	{
		ps_stack_action("rra", a, b);
		return;
	}
	else
	{
		ps_stack_action("sa", a, b);
		ps_stack_action("ra", a, b);
		return;
	}

}

void	ps_sort3(t_stack *a, t_stack *b)
{
	t_index_node	*mid_mode;

	if (ps_stack_is_sorted(a) == 1)
		return ;
	mid_mode = a->bot->next;
	if (a->top->index > a->bot->index)
	{
		if (a->top->index > mid_mode->index)
			tail_is_largest(a, b);
		else
			mid_is_largest(a, b);
	}
	else
	{
		if (a->bot->index > mid_mode->index)
			ps_stack_action("sa",a, b);
		else
			mid_is_largest(a, b);
	}
}
