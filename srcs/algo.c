/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:47:16 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/01 00:36:28 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"



// void	ps_sort_large(t_ps_stack *a, t_ps_stack *b)
// {
// 	t_ps_node	*cur_node_a;
// 	int			value_a;

// 	cur_node_a = a->tail;
// 	value_a = cur_node_a->value;
// 	while (ps_stack_count_clusters(a) != 1)
// 	{
// 		if (cur_node_a->cluster == 1 || cur_node_a->cluster == 2)
// 			ps_action_cluster12(a, b);
// 		else
// 			ps_action_cluster3(a, b);
// 		cur_node_a = a->tail;
// 		ft_debug_print_stacks(a, b);
// 	}
// 	while(ps_stack_count_clusters(a) != a->cluster_count)
// 	{
// 	}
// }

static inline void	ps_sort_mid(t_ps_stack *a, t_ps_stack *b)
{
	ps_push(a, b);
	
}

void	ps_sort(t_ps_stack *a, t_ps_stack *b)
{
	if (a->max_clusters == 1)
	{
		ps_sort3(a);
	
	}
	else
	{
		ps_sort_large(a, b);
	}
	// else if (a->max_clusters == 2)
	// {
	// 	ps_sort_mid(a, b);
	// }
}