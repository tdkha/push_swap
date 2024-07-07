/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_phase2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:11:07 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/06 21:28:10 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"
#include "../includes/push_swap.h"

static void	phase2_push(
	t_data *data,
	t_stack *a,
	t_stack *b,
	int	cur_pair)
{
	if (b->size > 0)
	{
		//--------------------------------------------------
		// REVERSE ROTATE
		//--------------------------------------------------
		if (b->size >= 1 && b->top->in_pair != cur_pair 
			&& b->bot->in_pair == cur_pair)
		{
			ps_stack_action("rrb", a, b);
		}
		//--------------------------------------------------
		// PUSH 
		//--------------------------------------------------
		if (b->top->in_pair == cur_pair)
		{
			ps_stack_action("pa", a, b);
		}
	}
	
}

static void	phase2_adjust(
	t_data *data,
	t_stack *a,
	t_stack *b,
	int	cur_pair)
{
	int				insert_pos;
	int				iteraton;
	t_index_node	*pivot_node;

	pivot_node = a->top;
	insert_pos = find_insert_pos_from_top(a, pivot_node, cur_pair);
	iteraton = 0;
	if (insert_pos == 0)
		return ;
	if (insert_pos == a->size - 1)
	{
		ps_stack_action("ra", a, b);
		return ;
	}
	if (insert_pos <= (a->size) / 2 + 1)
	{
		iteraton = insert_pos;
		adjust_top(a, b, iteraton, pivot_node);
	}
	else
	{
		iteraton = a->size - 1 - insert_pos;
		// printf("Insert pos: %d\n", insert_pos);
		// printf("Itertaion: %d\n", iteraton);
		adjust_bot(a, b, iteraton, pivot_node);
	}
}

void	phase2(t_data *data, t_stack *a, t_stack *b)
{
	// printf("--------------------------------\n");
	// printf("Phase 2\n");
	// printf("--------------------------------\n");
	int				cur_pair;
	int				cur_pair_exist;
	
	cur_pair = data->max_pairs;
	while (cur_pair > 0)
	{
		cur_pair_exist = ft_pair_exist(b, cur_pair);
		if (cur_pair_exist > 0)
			break ;
		cur_pair--;
	}
	while (cur_pair_exist > 0)
	{
		if (b->size == 0)
			break ;
		phase2_push(data, a, b, cur_pair);
		phase2_adjust(data, a, b, cur_pair);
		cur_pair_exist = ft_pair_exist(b, cur_pair);
		if (cur_pair_exist == 0 && cur_pair > 0)
		{
			cur_pair--;
			cur_pair_exist = ft_pair_exist(b, cur_pair);
		}
		// ft_debug_print_stacks(a, b);
	}
}
