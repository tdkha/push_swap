/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_large.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:10:41 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/02 06:54:02 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"

static inline void sort_large_phase1(
    t_ps_stack *a,
    t_ps_stack *b,
    int *min_cluster,
    int *max_cluster)
{
	int	max_iter;

	max_iter = a->max_clusters / 2;
	while (max_iter > 0 && a->size > 3)
	{
		if (maintain_three_highest(a))
			continue;
		if (!check_to_push(a, *min_cluster, *max_cluster))
		{
			max_iter--;
			*min_cluster += 2;
			*max_cluster += 2;
			continue;
		}
		if (a->tail->cluster == *min_cluster)
		{
			ps_push(a, b);
			ps_rotate(b);
		}
		else if (a->tail->cluster == *max_cluster)
			ps_push(a, b);
		else
			ps_rotate(a);
	}
}

static inline int find_insert_position(t_ps_stack *stack, int value)
{
	t_ps_node	*cur_node;
	int			position;

	cur_node = stack->tail;
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

static inline void	adjust_top(
	t_ps_stack *a,
	int iteration,
	t_ps_node *pivot_node)
{
	int	iter;
	
	iter = iteration;
	if (iter == 0)
		return;
	else if (iter == 1)
	{
		ps_swap(a);
		return;
	}
	while (iter > 0)
	{
		ps_swap(a);
		ps_rotate(a);
		iter--;
	}
	iter = iteration;
	while (iter > 0)
	{
		ps_rrotate(a);
		iter--;
	}	
}

/**
 * Formula: ra -> sa -> ra -> sa -> ... -> (ra * n)
 * Description:
 * 	<1>	Do <rotate> and <swap> for n times
 * 	<2> Rotate n + 1 times (because of the newly added node)
 */
static inline void	adjust_bot(
	t_ps_stack *a,
	int iteration,
	t_ps_node *pivot_node)
{
	int	iter;
	
	iter = iteration;
	if (iter == 0)
		return;
	if (pivot_node->value > a->head->value)
	{
		ps_rotate(a);
		return ;
	}
	while (iter > 0)
	{
		ps_rrotate(a);
		ps_swap(a);
		iter--;
	}
	iter = iteration + 1;
	while (iter > 0)
	{
		ps_rotate(a);
		iter--;
	}	
}

/**
 * Function to adjust the position of the newly added node at the top of the stack
 * Note: since we add a new node at the top, 
 * the <iteration> for adjust_top must be subtracted by 1
 */
static inline void adjust_position(
	t_ps_stack *a,
	int index,
	t_ps_node *pivot_node)
{
	int	iteration; 

	iteration = 0;
	if (index < a->size / 2)
	{
		iteration = index - 1;
		adjust_top(a, iteration, pivot_node);
	}
	else
	{
		iteration = a->size - index;
		adjust_bot(a, iteration, pivot_node);
	}
}

static inline void	sort_large_phase2(
    t_ps_stack *a,
    t_ps_stack *b,
	int *min_cluster,
	int *max_cluster
)
{
	t_ps_node	*pivot_node;
	int			insert_pos;
	int			clusters_to_push;
	
	clusters_to_push = ps_stack_find_clusters(b, *min_cluster, *max_cluster);
	while (clusters_to_push > 0 && (a->tail->cluster == 4 || a->tail->cluster == 3 || a->tail->cluster == 2 || a->tail->cluster == 1))
	{
		if (clusters_to_push == 1)
		{
			ps_rrotate(b);
			ps_push(b, a);
		}
		else if (clusters_to_push == 2)
			ps_push(b, a);
		pivot_node = a->tail;
		insert_pos = find_insert_position(a, pivot_node->value);
		adjust_position(a, insert_pos, pivot_node);
		clusters_to_push = ps_stack_find_clusters(b, *min_cluster, *max_cluster);
		{
			*min_cluster -= 2;
			*max_cluster -= 2;
			clusters_to_push = 2;
		}
		ft_debug_print_stacks(a, b);
	}
}


void	ps_sort_large(t_ps_stack *a, t_ps_stack *b)
{
	int min_cluster;
	int max_cluster;

	min_cluster = 1;
	max_cluster = 2;
	sort_large_phase1(a, b, &min_cluster, &max_cluster);
	if (a->size == 3)
		ps_sort3(a);
	sort_large_phase2(a, b, &min_cluster, &max_cluster);
}