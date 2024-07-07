/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_phase2_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:27:40 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/06 17:59:44 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"
#include "../includes/push_swap.h"

int find_insert_pos_from_top(
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

static int need_swap_b(
	t_stack *a, 
	t_stack *b,
	t_index_node *b_top,
	t_index_node	*b_prev
	)
{
	int	b_top_to_a_top;
	int	b_top_to_a_bot;
	int	b_prev_to_a_top;
	int	b_prev_to_a_bot;
	
	if (b->size < 2 || a->size < 1)
		return 0;
	b_top_to_a_top = ft_abs(b_top->value - a->top->value);
	b_top_to_a_bot = ft_abs(b_top->value - a->bot->value);
	b_prev_to_a_top = ft_abs(b_prev->value - a->top->value);
	b_prev_to_a_bot = ft_abs(b_prev->value - a->bot->value);
	// printf("--------------------------------------\n");
	// printf("Top node\n");
	// printf("--------------------------------------\n");
	// printf("Dist to top: %d\n", b_top_to_a_top);
	// printf("Dist to bot: %d\n", b_top_to_a_bot);
	// printf("--------------------------------------\n");
	// printf("Prev node\n");
	// printf("--------------------------------------\n");
	// printf("Dist to top: %d\n", b_prev_to_a_top);
	// printf("Dist to bot: %d\n", b_prev_to_a_bot);
	if (b_prev_to_a_bot < b_top_to_a_bot || b_prev_to_a_top < b_top_to_a_top)
	{
		return (1); // Need to swap
	}
	return (0); // No need to swap
}

void	optimized_action(
	char *str,
	t_stack *a,
	t_stack *b,
	t_index_node *pivot_node
)
{
	int	need_sb;
	
	need_sb = 0;
	if (ft_strnstr(str, "rra", sizeof(str)))
	{
		if (b->size >= 1 
			&& pivot_node->in_pair == b->bot->in_pair
			&& b->top->in_pair != pivot_node->in_pair
		)
		{
			ps_stack_action("rrr", a, b);
		}
		else
			ps_stack_action("rra", a, b);
	}
	else if (ft_strnstr(str, "sa", sizeof(str)))
	{
		if (a && b && (b->size >= 2 && a->size >= 1))
			need_sb = need_swap_b(a, b, b->top, b->top->prev);
		if (need_sb == 1)
			ps_stack_action("ss", a, b);			
		else
			ps_stack_action("sa", a, b);
	}
}



void	adjust_top(
	t_stack *a,
	t_stack *b,
	int iteration,
	t_index_node *pivot_node
)
{
	int	tmp_iter;

	tmp_iter = iteration;
	while (tmp_iter-- > 0)
	{
		//ps_stack_action("sa", a, b);
		optimized_action("sa", a, b, pivot_node);
		ps_stack_action("ra", a, b);
	}
	tmp_iter = iteration;
	while (tmp_iter-- > 0)
	{
		optimized_action("rra", a, b, pivot_node);
	}
}

void	adjust_bot(
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
	while (tmp_iter > 0)
	{
		optimized_action("rra", a, b, pivot_node);
		// ps_stack_action("sa", a, b);
		optimized_action("sa", a, b, pivot_node);
		tmp_iter--;
	}
	tmp_iter = iteration + 1;
	while (tmp_iter > 0)
	{
		ps_stack_action("ra", a, b);
		tmp_iter--;
	}
}