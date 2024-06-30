/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_large.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:10:41 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/01 00:40:13 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"

// static inline void ps_phase1_cluster12(t_ps_stack *a, t_ps_stack *b)
// {
// 	t_ps_node	*tail_a;
// 	t_ps_node	*tail_b;

// 	tail_a = a->tail;
// 	ps_push(a, b);
// 	tail_b = b->tail;
// 	if (tail_b && tail_b->cluster == 2 && b->size >= 2)
// 	{
// 		ps_rotate(b);
// 	}
// }

// static inline void ps_phase1_cluster3(t_ps_stack *a, t_ps_stack *b)
// {
// 	t_ps_node	*tail_a;
// 	t_ps_node	*head_a;

// 	tail_a = a->tail;
// 	head_a = a->head;
// 	ps_rotate(a);
// 	if (head_a->cluster == 1 || head_a->cluster == 2)
// 	{
// 		ps_push(a, b);
// 	}
// }

// void	ps_sort_large_phase1(t_ps_stack *a, t_ps_stack *b)
// {
// 	t_ps_node	*tail_a;
// 	int			value_a;

// 	tail_a = a->tail;
// 	value_a = tail_a->value;
// 	while (ps_stack_count_clusters(a) != 1)
// 	{
// 		if (tail_a->cluster == 1 || tail_a->cluster == 2)
// 			ps_phase1_cluster12(a, b);
// 		else
// 			ps_phase1_cluster3(a, b);
// 		tail_a = a->tail;
// 		ft_debug_print_stacks(a, b);
// 	}
// }

int	check_clusters(t_ps_stack *stack, int cluster1, int cluster2)
{
	t_ps_node	*cur_node;

	cur_node = stack->head;
	while (cur_node)
	{
		if (cur_node->cluster == cluster1)
		{
			return (1);
		}
		else if (cur_node->cluster == cluster2)
		{
			return (1);
		}
		cur_node = cur_node->next;
	}
	return (0);
}

void sort_large_phase1(t_ps_stack *a, t_ps_stack *b)
{
    int iter;
    int max_iter;
    int min_cluster;
    int max_cluster;

    iter = 1;
    max_iter = a->max_clusters / 2;
    min_cluster = 1;
    max_cluster = 2;
    while (iter <= max_iter)
	{
        if (!check_clusters(a, min_cluster, max_cluster))
		{
            iter++;
            min_cluster += 2;
            max_cluster += 2;
            continue;
        }
        if (a->tail->cluster == min_cluster)
		{
            ps_push(a, b);
            ps_rotate(b);
        }
		else if (a->tail->cluster == max_cluster)
            ps_push(a, b);
        else
            ps_rotate(a);
    }
}

void	sort_large_phase2(t_ps_stack *a, t_ps_stack *b)
{
	
}


void	ps_sort_large(t_ps_stack *a, t_ps_stack *b)
{
	sort_large_phase1(a, b);
}