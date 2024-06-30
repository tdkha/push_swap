/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:20:14 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/30 19:48:28 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"



int	ps_stack_count_clusters(t_ps_stack *stack)
{
	t_ps_node	*cur_node;
	int			*check;
	int			count;
	int			cluster_to_index;
	
	check = (int *) malloc (sizeof(int) * (stack->max_clusters));
	if (!check)
	{
		ft_printf_fd(2, "push_swap: Malloc error in <ps_stack_count_clusters>\n");
		exit(1);
	}
	count = 0;
	if (!stack->tail)
		return (0);

	for (int i = 0; i < stack->max_clusters; i++)
	{
		check[i] = 0;
	}
	cur_node = stack->head;
	while (cur_node)
	{
		cluster_to_index = cur_node->cluster - 1;
		if (cluster_to_index >= 0 && cluster_to_index < 3)
		{
			if (check[cluster_to_index] == 0)
			{
				check[cluster_to_index] = 1;
				count++;
			}
		}
		cur_node = cur_node->next;
	}
	return (count);
}


