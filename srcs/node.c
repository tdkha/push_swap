/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:37:13 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/03 00:39:07 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"
#include "../includes/push_swap.h"

t_index_node	*ps_node_init(int value)
{
	t_index_node *node;

	node = (t_index_node *) malloc (sizeof(t_index_node));
	if (!node)
	{
		ft_exit("Failed to malloc a <t_index_node> instance", 1);
	}
	node->value = value;
	node->in_pair = 0;
	node->next = NULL;
	node->prev = NULL;
	return(node);
}
