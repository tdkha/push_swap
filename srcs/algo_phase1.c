/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_phase1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:32:19 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/05 12:46:47 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/algo.h"
#include "../includes/push_swap.h"

static void	phase1_push_rotate(
	t_data *data,
	t_stack *a,
	t_stack *b,
	int cur_pair
)
{
	int	need_ra;
	int need_rb;
	int	mid;

	need_ra = 0;
	need_rb = 0;
	mid = ((cur_pair - 1) * data->amt_per_pair + cur_pair * data->amt_per_pair - 1) / 2;
			printf("Mid: %d\n", mid);

	if (a->top->in_pair == cur_pair)
	{
		ps_stack_action("pb",a ,b);
		if (ft_pair_exist(a, cur_pair) == 0 && a->top->in_pair != cur_pair - 1)
			need_ra = 1;
		if (b->size > 1 && b->top->value < mid)
			need_rb = 1;
	}
	else
		need_ra = 1;
	if (need_ra && need_rb)
		ps_stack_action("rr", a, b);
	else if (need_ra)
		ps_stack_action("ra", a, b);
	else if (need_rb)
		ps_stack_action("rb", a, b);
}

void	phase1(
	t_data *data,
	t_stack *a,
	t_stack *b)
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