/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_phase2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:11:07 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/05 16:25:31 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"
#include "../includes/push_swap.h"


static int find_insert_pos_from_top(
    t_stack *a, 
    t_index_node *top_node,
    int cur_pair)
{
	t_index_node	*cur_node;
	int				position;

	cur_node = a->top->prev;
	position = 0;

	if (cur_node == NULL)
		return 0;
	// printf("Cur node: %d\n", cur_node->value);
	// printf("Top node: %d\n", top_node->value);

	if (cur_node->value > top_node->value)
		return (0);
	if (cur_node->value > top_node->value && top_node->value < a->bot->value)
		return (1);
	while (cur_node)
	{
		if (cur_node->value > top_node->value)
			break ;
		cur_node = cur_node->prev;
		position++;
	}
	return (position);
}


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

static void	adjust_top(
	t_stack *a,
	t_stack *b,
	int iteration,
	t_index_node *pivot_node
)
{
	int				tmp_iter;

	tmp_iter = iteration;
	while (tmp_iter-- > 0)
	{
		ps_stack_action("sa", a, b);
		ps_stack_action("ra", a, b);
	}
	tmp_iter = iteration;
	while (tmp_iter-- > 0)
	{
		if (b->size >= 1 
			&& pivot_node->in_pair - 1 == b->bot->in_pair
			&& b->top->in_pair != pivot_node->in_pair
		)
		{
			ps_stack_action("rrr", a, b);
		}
		else
			ps_stack_action("rra", a, b);
	}
}

static void	adjust_bot(
	t_stack *a,
	t_stack *b,
	int iteration,
	t_index_node *pivot_node
)
{
	int				tmp_iter;
	t_index_node	*node;

	node = a->top;
	tmp_iter = iteration;
	if (a->bot && pivot_node->value > a->bot->value)
	{
		ps_stack_action("ra", a, b);
		return ;
	}
	while (tmp_iter-- > 0)
	{
		if (b->bot && pivot_node->in_pair - 1 == b->bot->in_pair)
			ps_stack_action("rrr", a, b);
		else
			ps_stack_action("rra", a, b);
	}
	tmp_iter = iteration + 1;
	while (tmp_iter-- > 0)
	{
		ps_stack_action("ra", a, b);
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

	// printf("Insert position: %d\n", insert_pos);
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
		iteraton = a->size - insert_pos;
		adjust_bot(a, b, iteraton, pivot_node);
	}
	// printf("Iteration: %d\n", iteraton);
}

void	phase2(t_data *data, t_stack *a, t_stack *b)
{
	// printf("--------------------------------\n");
	// printf("Phase 2\n");
	// printf("--------------------------------\n");
	
	int				cur_pair;
	int				cur_pair_exist;
	cur_pair = data->max_pairs;
	cur_pair_exist = ft_pair_exist(b, cur_pair);
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
