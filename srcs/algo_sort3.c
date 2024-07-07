/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 00:41:15 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/07 16:32:53 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"

static inline void tail_is_largest(t_stack *a, t_stack *b)
{
	ps_stack_action("ra", a, b);
	if (a->top->value > a->top->prev->value)
	{
		ps_stack_action("sa", a, b);
	}
}

static inline void mid_is_largest(t_stack *a, t_stack *b)
{
	if (a->top->value > a->bot->value)
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
	if (a->top->value > a->bot->value)
	{
		if (a->top->value > mid_mode->value)
			tail_is_largest(a, b);
		else
			mid_is_largest(a, b);
	}
	else
	{
		if (a->bot->value > mid_mode->value)
			ps_stack_action("sa",a, b);
		else
			mid_is_largest(a, b);
	}
}