/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:20:49 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/26 16:03:58 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

t_ps_node	*ps_node_init(int value)
{
	t_ps_node	*res;

	res = (t_ps_node *) malloc (sizeof(t_ps_node));
	res->value = value;
	res->prev = NULL;
	res->next = NULL;
	return (res);
}

void	ps_node_link_bidirection(
	t_ps_node *node,
	t_ps_node *prev,
	t_ps_node *next
)
{
	node->prev = prev;
	node->next = next;
	prev->next = node;
	next->prev = node;
}

void	ps_node_link(
	t_ps_node *node,
	t_ps_node *to_link,
	int is_linking_next
)
{
	if (is_linking_next)
	{
		node->next = to_link;
		to_link->prev = node;
	}
	else
	{
		node->prev = to_link;
		to_link->next = node;
	}
}
