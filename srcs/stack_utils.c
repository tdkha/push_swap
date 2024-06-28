/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:20:14 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/28 13:27:02 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static inline int stack_to_arr(t_ps_stack *stack, int *arr)
{
	int			i;
	t_ps_node	*node;

	if (stack->size <= 0)
		return (0);
	i = 0;
	node = stack->head;
	while (node)
	{
		arr[i] = node->value;
		node = node->next;
		i++;
	}
	return (1);
}

int	ps_stack_cluster_divide(t_ps_stack *stack)
{
	int			*arr;
	int			i;
	t_ps_node	*node;
	
	arr = (int *) malloc (sizeof(int) * stack->size);
	if (!arr)
		return (-1);
	if (stack_to_arr(stack, arr) == 0)
		return (0);
	for (i = 0; i < stack->size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return (1);
}
