/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_phase2_beta.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:28:41 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/07 22:34:17 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"

int	find_max_top_same_pair(
	t_stack *b,
	int cur_pair,
	int *iter,
	int *found)
{
	t_index_node	*cur_node;
	int				max; 
	int				tmp_iter;

	*found = 0;
	*iter = 0;
	tmp_iter = 1;
	cur_node = b->top->prev;
	max = b->top->value;
	while (cur_node && cur_node->in_pair == cur_pair)
	{
		if (max < cur_node->value)
		{
			max = cur_node->value;
			*found = 1;
			(*iter) = tmp_iter;
		}
		tmp_iter++;
		cur_node = cur_node->prev;
	}
	if (max == b->top->value)
	{
		*iter = 0;
		*found = 1;
	}
	return (max);
}


int	find_max_bot_same_pair(
	t_stack *b,
	int cur_pair,
	int *iter,
	int	*found)
{
	t_index_node	*cur_node;
	int				max;
	int				tmp_iter;
	
	cur_node = b->bot->next;
	*found = 0;
	*iter = 0;
	tmp_iter = 2;
	max = b->bot->value;
	while (cur_node && cur_node->in_pair == cur_pair)
	{
		if (max < cur_node->value)
		{
			max = cur_node->value;
			*found = 1;
			(*iter) = tmp_iter;
		}
		tmp_iter++;
		cur_node = cur_node->next;
	}
	if (max == b->bot->value)
	{
		*iter = 1;
		*found = 1;
	}
	return (max);
}

int find_adjacent_node(
	t_stack *b,
	int cur_pair,
	int *iter
)
{
	int	iteration;

}


/**
 * Function to move the largest value within the top pair to the top by rotating
 * <cur_node> in this case is the top node of stack B
 */
int	max_top_to_top(
	t_data *data,
	t_stack *a,
	t_stack *b,
	int	cur_pair)
{
	int				max_top;
	int				max_bot;
	int				iter[2] = {0};
	int				found[2] = {0};

	if (!a || !b || b->size <= 1)
		return (0);
	if (b->size >= 2)
	{
		if (b->top->value == a->top->value - 1)
			return (1);
		else
		{
			max_top = find_max_top_same_pair(b, cur_pair, &iter[0], &found[0]);
			max_bot = find_max_bot_same_pair(b, cur_pair, &iter[1], &found[1]);
			printf("Max top: %d\n", max_top);
		printf("Max bot: %d\n", max_bot);
		printf("Iter top: %d\n", iter[0]);
		printf("Iter bot: %d\n", iter[1]);
		printf("Found top: %d\n", found[0]);
			if (max_top == max_bot && iter[0] > iter[1])
					return (0);
			if (max_top < max_bot)
				return (0);
			while (iter[0]-- > 0)
				ps_stack_action("rb", a, b);
		}
	}
	return (found[0]);
}

		// printf("Max top: %d\n", max_top);
		// printf("Max bot: %d\n", max_bot);
		// printf("Iter top: %d\n", iter);
		// printf("Iter bot: %d\n", tmp_iter);
		// printf("Found top: %d\n", found[0]);

/**
 * Function to move the largest value within the bot pair to the top by reverse rotating
 * <cur_node> in this case is the bot node of stack B
 */
int	max_bot_to_top(
	t_data *data,
	t_stack *a,
	t_stack *b,
	int	cur_pair
)
{
	int				iter;
	int				max;
	int				found;

	if (!a || !b || b->size <= 1)
		return (0);
	found = 0;
	iter = 0;
	max = b->bot->value;
	find_max_bot_same_pair(b, cur_pair, &iter, &found);
	// printf("Iter bot: %d\n", iter);
	while (iter-- > 0)
		ps_stack_action("rrb", a, b);
	return (found);
}

static int node_is_min(
	t_stack *a,
	t_stack *b,
	int	cur_pair)
{
	t_index_node	*node;
	int				min;

	if (!a || !b || b->size <= 2)
		return (0);
	if (b->top->value == a->top->value - 1)
		return (0);
	node = b->top;
	min = b->top->value;
	while (node && node->in_pair == cur_pair)
	{
		if(min > node->value)
			min = node->value;
		node = node->prev;
	}
	if (min == b->top->value)
	{
		return (1);
	}
	return (0);
}

void	phase2_push_max(
	t_data *data,
	t_stack *a,
	t_stack *b,
	int cur_pair)
{
	int	top_min_found;
	int	top_found;
	int	bot_found;

	top_found = 0;
	bot_found = 0;
	if (b->size > 0)
	{
		if (b->top->in_pair == cur_pair)
		{
			top_min_found = node_is_min(a, b, cur_pair);
			if (top_min_found == 0)
				top_found = max_top_to_top(data, a, b, cur_pair);
		}
		if (top_min_found == 0 && top_found == 0 && b->bot->in_pair == cur_pair)
			bot_found = max_bot_to_top(data, a, b, cur_pair);
		printf("Found: %d %d %d\n",top_min_found, top_found, bot_found);
		if (top_found || bot_found || b->size == 1)
			ps_stack_action("pa", a, b);
		if (top_min_found)
		{
			ps_stack_action("pa", a, b);
			ps_stack_action("ra", a, b);
		}
	}
}

void	phase2_check_rotate(
	t_data *data,
	t_stack *a,
	t_stack *b,
	int cur_pair)
{
	int				need_rra;
	int 			need_rrb;
	int				need_rrr;
	t_index_node	*node;

	need_rra = 0;
	need_rrb = 0;
	need_rrr = 0;
	node = a->bot;
	while (node && a->bot->value == a->top->value - 1)
	{
		if (node->value < node->next->value)
		{
			need_rra++;
			break ;
		}
		need_rra++;
		node = node->next;
	}
	if (b->size >= 2)
	{
		node = b->bot;
		while (b->top->in_pair != cur_pair
			&& node && node->in_pair == cur_pair)
		{
			need_rrb++;
			node = node->next;
		}
	}
	if (need_rra < need_rrb)
	{
		need_rrr = need_rra;
		need_rrb -= need_rra;
		need_rra = 0;
	}
	else
	{
		need_rrr = need_rrb;
		need_rra -= need_rrb;
		need_rrb = 0;
	}
	while (need_rrr-- > 0)
		ps_stack_action("rrr", a, b);
	while (need_rra-- > 0)
		ps_stack_action("rra", a, b);
	while (need_rrb-- > 0)
		ps_stack_action("rrb", a, b);
}


void	phase2(t_data *data, t_stack *a, t_stack *b)
{
	t_actions		actions = {0};
	int				cur_pair;
	int				cur_pair_exist;
	
	cur_pair = data->max_pairs;
	while (cur_pair > 0)
	{
		cur_pair_exist = ft_pair_exist(b, cur_pair);
		if (cur_pair_exist > 0 || cur_pair != data->max_pairs)
			break ;
		cur_pair--;
	}
	while (cur_pair_exist > 0)
	{
		if (b->size == 0)
			break ;
		phase2_push_max(data, a, b, cur_pair);
		// if (a->size >= 2 && b->size >= 2)
		phase2_check_rotate(data, a, b, cur_pair);
		cur_pair_exist = ft_pair_exist(b, cur_pair);
		if (cur_pair_exist == 0 && cur_pair > 0)
		{
			cur_pair--;
			cur_pair_exist = ft_pair_exist(b, cur_pair);
		}
		ft_debug_print_stacks(a, b);
	}
}