/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_large_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:42:20 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/03 00:14:33 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"

/*+------------------------------------------------------------+*/
//	PHASE 1
/*+------------------------------------------------------------+*/

/**
 * Function to maintain the highest cluster in stack a
 * Description:
 * 	<1>	Calculate a number of cluster in stack a
 * 	<2>	Make the second largest cluster come to the top to push
 */
inline int maintain_three_highest(t_stack *stack)
{
	t_index_node	*cur_node;
	int		highest_cluster;
	int		highest_cluster_count;

	cur_node = stack->bot;
	highest_cluster = stack->max_clusters;
	highest_cluster_count = 0;
	if (!stack || !stack->bot)
		return (0);
	while (cur_node)
	{
		if (cur_node->in_pair == highest_cluster)
			highest_cluster_count++;
		cur_node = cur_node->next;
	}
	if (highest_cluster_count == 3 && ps_stack_count_clusters(stack) == 2)
	{
		if (stack->top->in_pair != highest_cluster)
			return (0);
		while (stack->top->in_pair == highest_cluster)
			ps_rotate(stack);
		return (1);
	}
	return (0);
}

/**
 * Function to check if the push operation is needed
 * Description:
 * 	<1> Push if the current node's cluster is equal to
 * 		the current min and max clusters
 */
inline int check_to_push(t_stack *stack, int cluster1, int cluster2)
{
	t_index_node *cur_node;

	cur_node = stack->bot;
	while (cur_node)
	{
		if (cur_node->in_pair == cluster1 || cur_node->in_pair == cluster2)
			return (1);
		cur_node = cur_node->next;
	}
	return (0);
}

/*+------------------------------------------------------------+*/
//	PHASE 2
/*+------------------------------------------------------------+*/
