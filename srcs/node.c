/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:37:13 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/13 23:30:48 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"
#include "../includes/push_swap.h"

t_index_node	*ps_node_init(int index)
{
	t_index_node	*node;

	node = (t_index_node *) malloc (sizeof(t_index_node));
	if (!node)
	{
		return (NULL);
	}
	node->index = index;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
