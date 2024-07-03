/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:47:16 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/03 11:50:12 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"


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

void	phase1_check_rotate(t_stack *a, t_stack *b, int cur_pair)
{
	int	need_ra;
	int need_rb;
	
	need_ra = 0;
	need_rb = 0;
	if (a->top->in_pair != cur_pair)
		need_ra = 1;
	if (b->size > 1 && b->top->in_pair == cur_pair - 1)
		need_rb = 1;
	if (need_ra && need_rb)
		ps_rotate2(a, b);
	else if (need_ra)
		ps_rotate(a);
	else if (need_rb)
		ps_rotate(b);
}

void	phase1(t_stack *a, t_stack *b)
{
	printf("Phase 1\n");
	printf("--------------------------------\n");
	int				cur_pair;
	int				cur_pair_exist;

	cur_pair = a->pairs;
	cur_pair_exist = ft_pair_exist(a, cur_pair);
	while (cur_pair_exist > 0 && a->size > 3)
	{
		phase1_check_rotate(a, b, cur_pair);
		if (a->top->in_pair == cur_pair)
			ps_push(a, b);
		cur_pair_exist = ft_pair_exist(a, cur_pair);
		if (cur_pair_exist == 0 && cur_pair > 0)
		{
			cur_pair--;
			cur_pair_exist = ft_pair_exist(a, cur_pair);
		}
	}
	printf("--------------------------------\n");
	
}


void	ps_sort(t_stack *a, t_stack *b)
{
	if (a->size > 3)
	{
		phase1(a, b);
		ps_sort3(a);
	}
	else
		ps_sort3(a);
	
}