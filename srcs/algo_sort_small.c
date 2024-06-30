/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 00:12:23 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/01 00:35:06 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"

static inline void tail_is_largest(t_ps_stack *a)
{
	ps_rotate(a);
	if (a->tail->value > a->tail->prev->value)
	{
		ps_swap(a);
	}
}

static inline void mid_is_largest(t_ps_stack *a)
{
	if (a->tail->value > a->head->value)
	{
		ps_rrotate(a);
		ps_rrotate(a);
		return;
	}
	else
	{
		ps_rotate(a);
		ps_rotate(a);
		return;
	}

}

void	ps_sort3(t_ps_stack *a)
{
	t_ps_node	*mide_mode;
	
	mide_mode = a->head->next;
	if (a->tail->value > a->head->value)
	{
		if (a->tail->value > mide_mode->value)
			tail_is_largest(a);
		else
			mid_is_largest(a);
	}
	else
	{
		if (a->head->value > mide_mode->value)
			ps_swap(a);
		else
			mid_is_largest(a);
	}
}

void ps_sort4(t_ps_stack *a, t_ps_stack *b)
{
	t_ps_node *cur_node;
	int array[4] = {0};
	int min_index = 0;
	int max_index = 0;
	int i = 0;

	cur_node = a->head;
	while (cur_node)
	{
		array[i] = cur_node->value;
		if (i == 0 || cur_node->value < array[min_index])
			min_index = i;
		i++;
		cur_node = cur_node->next;
	}
	if (min_index == 0) {
		ps_push(a, b);
	} else if (min_index == 1) {
		ps_swap(a);
		ps_push(a, b);
	} else if (min_index == 2) {
		ps_rrotate(a);
		ps_rrotate(a);
		ps_push(a, b);
	} else if (min_index == 3) {
		ps_rrotate(a);
		ps_push(a, b);
	}
	ps_sort3(a);
	ps_push(b, a);
}

