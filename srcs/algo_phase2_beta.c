/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_phase2_beta.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:28:41 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/07 16:26:11 by ktieu            ###   ########.fr       */
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
	// printf("Max top: %d\n", max);
	// printf("TOP: %d\n", b->top->value);
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
		// printf("Max bot: %d\n", max);
		// printf("Bot: %d\n", b->bot->value);
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

/**
 * Function to move the largest value within the top pair to the top by rotating
 * <cur_node> in this case is the top node of stack B
 */
int	max_top_to_top(
	t_stack *a,
	t_stack *b,
	t_index_node *cur_node,
	int	cur_pair)
{
	int				max_top;
	int				max_bot;
	int				iter;
	int				found[2] = {0};
	int				tmp_iter;

	if (b->size <= 1 || cur_node != b->top)
		return (0);
	iter = 0;
	if (b->size >= 2)
	{
		max_top = find_max_top_same_pair(b, cur_pair, &iter, &found[0]);
		max_bot = find_max_bot_same_pair(b, cur_pair, &tmp_iter, &found[1]);
	}
	
	if (max_top == max_bot)
	{
		if (iter > tmp_iter)
			return (0);
	}
	// printf("Max top: %d\n", max_top);
	// printf("Max bot: %d\n", max_bot);
	// printf("Iter top: %d\n", iter);
	// printf("Iter bot: %d\n", tmp_iter);
	// printf("Found top: %d\n", found[0]);
	if (max_top < max_bot)
		return (0);
	while (iter-- > 0)
		ps_stack_action("rb", a, b);

	return (found[0]);
}

/**
 * Function to move the largest value within the bot pair to the top by reverse rotating
 * <cur_node> in this case is the bot node of stack B
 */
int	max_bot_to_top(
	t_stack *a,
	t_stack *b,
	t_index_node *cur_node,
	int	cur_pair
)
{
	int				iter;
	int				max;
	int				found;

	if (b->size <= 1 || cur_node != b->bot)
		return (0);
	found = 0;
	iter = 0;
	max = b->bot->value;
	// while (cur_node && cur_node->in_pair == cur_pair)
	// {
	// 	if (max <= cur_node->value && iter++)
	// 		max = cur_node->value;
	// 	cur_node = cur_node->next;
	// }
	find_max_bot_same_pair(b, cur_pair, &iter, &found);
	// printf("Iter bot: %d\n", iter);
	while (iter-- > 0)
		ps_stack_action("rrb", a, b);
	return (found);
}

void	phase2_push_max(t_stack *a, t_stack *b, int cur_pair)
{
	int	top_found;
	int	bot_found;

	top_found = 0;
	bot_found = 0;
	if (b->size > 0)
	{
		if (b->top->in_pair == cur_pair)
		{
			top_found = max_top_to_top(a, b, b->top, cur_pair);
		}
		if (top_found == 0 && b->bot->in_pair == cur_pair)
			bot_found = max_bot_to_top(a, b, b->bot, cur_pair);
		//printf("Found: %d %d\n", top_found, bot_found);
		if (top_found || bot_found || b->size == 1)
			ps_stack_action("pa", a, b);
	}
}

void	phase2_adjust(t_stack *a, t_stack *b, int cur_pair)
{
	static int	open_top;
	
	open_top = 0;
ps_stack_action("ra", a, b);
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
		if (cur_pair_exist > 0 || cur_pair != data->max_pairs)
			break ;
		cur_pair--;
	}
	while (cur_pair_exist > 0)
	{
		if (b->size == 0)
			break ;

		phase2_push_max(a,b , cur_pair);

		// printf("---------------------------------\n");
		// printf("Cur pair is: %d\n", cur_pair);
		// printf("---------------------------------\n");

		cur_pair_exist = ft_pair_exist(b, cur_pair);
		if (cur_pair_exist == 0 && cur_pair > 0)
		{
			cur_pair--;
			cur_pair_exist = ft_pair_exist(b, cur_pair);
		}
		// ft_debug_print_stacks(a, b);
	}
}