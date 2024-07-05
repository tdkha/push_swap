/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_phase2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:11:07 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/05 12:23:54 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"
#include "../includes/push_swap.h"

static int find_insert_position(t_stack *stack, int value)
{
	t_index_node	*cur_node;
	int			position;

	cur_node = stack->top;
	position = 0;
	if (cur_node->value < cur_node->prev->value)
		return (0);
	while (cur_node)
	{
		if (cur_node->value > value)
			break;
		cur_node = cur_node->prev;
		position++;
	}
	return (position);
}

/**
 * 1 is top
 * 0 is bot
 */
static int	top_or_bot(
	t_stack *a,
	t_stack *b,
	t_index_node *node,
	int cur_pair
)
{
	int res;
	int	i;

	i = 0;
	if (node->value < a->top->value)
		return (1);
	if (node->value > a->bot->value)
		return (0);
	return (1);
	// while (	)
	// {
	// 	i++;
	// }
}

static int	dist_top_or_bot(
	t_stack *a,
	t_stack *b,
	t_index_node *node,
	int cur_pair
)
{
	int distance;

	if (node->value < a->top->value)
		return (0);
	if (node->value > a->bot->value)
		return (a->size - 1);

	distance = 0;
	return (distance);
}

static void	phase2_push(
	t_data *data,
	t_stack *a,
	t_stack *b,
	int	cur_pair)
{
	
	int	need_rra;
	int need_rrb;

	need_rra = 0;
	need_rrb = 0;
	//--------------------------------------------------

	// REVERSE ROTATE
	//--------------------------------------------------
	if (b->top->in_pair != cur_pair && b->bot->in_pair == cur_pair)
		need_rrb = 1;
	if (b->top->value > a->top->value)
		need_rra = 1;
	if (need_rra && need_rrb)
		ps_stack_action("rrr", a, b);
	else if (need_rra)
		ps_stack_action("rra", a, b);
	else if (need_rrb)
		ps_stack_action("rrb", a, b);
		
	//--------------------------------------------------
	// PUSH 
	//--------------------------------------------------

	if (b->top->in_pair == cur_pair)
	{
		ps_stack_action("pa", a, b);
	}
	// else
	// {
	// 	if (b->bot->in_pair == cur_pair)
	// 	{
	// 		ps_stack_action("pa",a,b);
	// 	}
	// }
}

void	phase2(t_data *data, t_stack *a, t_stack *b)
{
	printf("--------------------------------\n");
	printf("Phase 2\n");
	printf("--------------------------------\n");
	
	int				cur_pair;
	int				cur_pair_exist;
	cur_pair = data->max_pairs;
	cur_pair_exist = ft_pair_exist(b, cur_pair);
	while (cur_pair_exist > 0)
	{
		if (cur_pair == 1)
			break ;
		// phase2_push(data, a, b);
		cur_pair_exist = ft_pair_exist(b, cur_pair);
		if (cur_pair_exist == 0 && cur_pair > 0)
		{
			cur_pair++;
			cur_pair_exist = ft_pair_exist(b, cur_pair);
		}
	}
}