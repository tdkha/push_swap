/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:47:16 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/04 11:52:43 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"
#include "../includes/push_swap.h"

static int	ft_pair_exist(t_stack *stack, int pair)
{
	t_index_node	*node;

	node = stack->top;
	while (node)
	{
		if (node->in_pair == pair)
			return (1);
		node = node->prev;
	}
	return (0);
}


void	phase1_push_rotate(
	t_data *data,
	t_stack *a, t_stack *b,
	int cur_pair
)
{
	int	need_ra;
	int need_rb;
	int	mid;

	need_ra = 0;
	need_rb = 0;
	mid = ((cur_pair - 1) * data->amt_per_pair + cur_pair * data->amt_per_pair - 1) / 2;
	if (a->top->in_pair == cur_pair)
	{
		ps_stack_action("pb",a ,b);
		if (b->size > 1 && b->top->value < mid)
		{
			// printf("amt_per_pair: %d\n", data->amt_per_pair);
			// printf("mid: %d\n", mid);
			need_rb = 1;
		}
	}
	if (a->top->in_pair != cur_pair)
		need_ra = 1;
	if (b->size > 1 && b->top->in_pair == cur_pair - 1)
		need_rb = 1;
	if (need_ra && need_rb)
		ps_stack_action("rr", a, b);
	else if (need_ra)
		ps_stack_action("ra", a, b);
	else if (need_rb)
		ps_stack_action("rb", a, b);
}

static void	phase1(t_data *data, t_stack *a, t_stack *b)
{
	printf("--------------------------------\n");
	printf("Phase 1\n");
	printf("--------------------------------\n");
	int				cur_pair;
	int				cur_pair_exist;

	cur_pair = 1;
	cur_pair_exist = ft_pair_exist(a, cur_pair);
	while (cur_pair_exist > 0 && a->size > 3)
	{
		if (cur_pair == data->max_pairs && a->size == 3)
			break ;
		phase1_push_rotate(data, a, b, cur_pair);
		cur_pair_exist = ft_pair_exist(a, cur_pair);
		if (cur_pair_exist == 0 && cur_pair > 0)
		{
			cur_pair++;
			cur_pair_exist = ft_pair_exist(a, cur_pair);
		}
		ft_debug_print_stacks(a,b);
	}
}

static void	phase2(t_data *data, t_stack *a, t_stack *b)
{
	printf("--------------------------------\n");
	printf("Phase 2\n");
	printf("--------------------------------\n");
	
	int				cur_pair;
	int				cur_pair_exist;
	cur_pair = data->max_pairs;
	cur_pair_exist = ft_pair_exist(a, cur_pair);
}


void	ps_sort(t_data *data, t_stack *a, t_stack *b)
{
	if (a->size > 3)
	{
		phase1(data, a, b);
		ps_sort3(a);
		phase2(data, a, b);
	}
	else
		ps_sort3(a);
}