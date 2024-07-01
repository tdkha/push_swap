/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:20:14 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/01 17:49:56 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"



int ps_stack_count_clusters(t_ps_stack *stack)
{
    if (!stack || !stack->head || stack->max_clusters <= 0)
        return 0;

    int *check = (int *)malloc(sizeof(int) * stack->max_clusters);
    if (!check)
    {
        fprintf(stderr, "push_swap: Malloc error in <ps_stack_count_clusters>\n");
        exit(1);
    }

    for (int i = 0; i < stack->max_clusters; i++)
    {
        check[i] = 0;
    }

    int count = 0;
    t_ps_node *cur_node = stack->head;

    while (cur_node)
    {
        int cluster_to_index = cur_node->cluster - 1;
        if (cluster_to_index >= 0 && cluster_to_index < stack->max_clusters)
        {
            if (check[cluster_to_index] == 0)
            {
                check[cluster_to_index] = 1;
                count++;
            }
        }
        cur_node = cur_node->next;
    }

    free(check);
    return count;
}

int	ps_stack_find_cluster(t_ps_stack *stack, int cluster)
{
	t_ps_node	*node;

	node = stack->head;
	while (node)
	{
		if (node->cluster == cluster)
			return (1);
		node = node->next;
	}
	return (0);
}

int	ps_stack_find_clusters(t_ps_stack *stack, int c1, int c2)
{
	int			found_c1;
	int			found_c2;
	t_ps_node	*node;

	found_c1 = 0;
	found_c2 = 0;
	node = stack->head;
	while (node)
	{
		if (node->cluster == c1)
			found_c1 = 1;
		else if (node->cluster == c2)
			found_c2 = 1;
		node = node->next;
	}
	return (found_c1 + found_c2);
}