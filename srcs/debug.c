/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:56:14 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/09 15:55:14 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_debug_print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_index_node	*cur_node_a;
	t_index_node	*cur_node_b;

	cur_node_a = stack_a->top;
	cur_node_b = stack_b->top;
	printf("Stack A Size:\t%d\t\tStack B Size:\t%d\n", stack_a->size, stack_b->size);
	printf("Stack A Head:\t%d\t\tStack B Head:\t%d\n", stack_a->bot ? stack_a->bot->index : -42, stack_b->bot ? stack_b->bot->index : -42);
	printf("Stack A top:\t%d\t\tStack B top:\t%d\n", stack_a->top ? stack_a->top->index : -42, stack_b->top ? stack_b->top->index : -42);
	printf("-+--------------+-\t\t-+--------------+-\n");

	while (cur_node_a || cur_node_b)
	{
		if (cur_node_a)
			printf(" |     %d[%d]     |", cur_node_a->index, cur_node_a->index);
		else
			printf(" |              |");
		printf("\t\t");
		if (cur_node_b)
			printf(" |     %d[%d]     |\n", cur_node_b->index, cur_node_b->index);
		else
			printf(" |              |\n");
		if (cur_node_a)
			cur_node_a = cur_node_a->prev;
		if (cur_node_b)
			cur_node_b = cur_node_b->prev;
	}
	printf("-+--------------+-\t\t-+--------------+-\n");
}


