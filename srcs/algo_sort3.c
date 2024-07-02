/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 00:41:15 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/03 00:42:38 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"

static inline void tail_is_largest(t_stack *a)
{
	ps_rotate(a);
	if (a->top->value > a->top->prev->value)
	{
		ps_swap(a);
	}
}

static inline void mid_is_largest(t_stack *a)
{
	if (a->top->value > a->bot->value)
	{
		ps_rrotate(a);
		return;
	}
	else
	{
		ps_swap(a);
		ps_rotate(a);
		return;
	}

}

void	ps_sort3(t_stack *a)
{
	t_index_node	*mid_mode;

	if (ps_stack_is_sorted(a) == 1)
		return ;
	mid_mode = a->bot->next;
	if (a->top->value > a->bot->value)
	{
		if (a->top->value > mid_mode->value)
			tail_is_largest(a);
		else
			mid_is_largest(a);
	}
	else
	{
		if (a->bot->value > mid_mode->value)
			ps_swap(a);
		else
			mid_is_largest(a);
	}
}