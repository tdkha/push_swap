/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:56:14 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/30 15:28:18 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_debug_print_stack(t_ps_stack *stack)
{
	t_ps_node	*cur_node;
	
	cur_node = stack->tail;
	if (!cur_node)
		ft_exit("No node in stack", 0);
	printf("Stack Size:\t%ld\n", stack->size);
	printf("Stack Head:\t%d\n", stack->head ? stack->head->value : -42);
	printf("Stack Tail:\t%d\n", stack->tail ? stack->tail->value : -42);
	printf("-+--------------+-\n");
	while (cur_node)
	{
		printf(" |              | \n");
		printf(" |      %d       | \n", cur_node->value);
		printf(" |              | \n");
		cur_node = cur_node->prev;
	}
	printf("-+--------------+-\n");
}

void	ft_debug_print_stack_cluster(t_ps_stack *stack)
{
	t_ps_node	*cur_node;
	
	cur_node = stack->tail;
	printf("Stack Size:\t%ld\n", stack->size);
	printf("Stack Head:\t%d\n", stack->head ? stack->head->value : -42);
	printf("Stack Tail:\t%d\n", stack->tail ? stack->tail->value : -42);
	printf("-+--------------+-\n");
	while (cur_node)
	{
		printf(" |              | \n");
		printf(" |    %d [%d]     | \n", cur_node->value, cur_node->cluster);
		printf(" |              | \n");
		cur_node = cur_node->prev;
	}
	printf("-+--------------+-\n");
}

void	ft_debug_print_stacks(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	t_ps_node	*cur_node_a;
	t_ps_node	*cur_node_b;

	cur_node_a = stack_a->tail;
	cur_node_b = stack_b->tail;
	printf("Stack A Size:\t%ld\t\tStack B Size:\t%ld\n", stack_a->size, stack_b->size);
	printf("Stack A Head:\t%d\t\tStack B Head:\t%d\n", stack_a->head ? stack_a->head->value : -42, stack_b->head ? stack_b->head->value : -42);
	printf("Stack A Tail:\t%d\t\tStack B Tail:\t%d\n", stack_a->tail ? stack_a->tail->value : -42, stack_b->tail ? stack_b->tail->value : -42);
	printf("-+--------------+-\t\t-+--------------+-\n");

	while (cur_node_a || cur_node_b)
	{
		if (cur_node_a)
			printf(" |     %d[%d]     |", cur_node_a->value, cur_node_a->cluster);
		else
			printf(" |              |");
		printf("\t\t");
		if (cur_node_b)
			printf(" |     %d[%d]     |\n", cur_node_b->value, cur_node_b->cluster);
		else
			printf(" |              |\n");
		if (cur_node_a)
			cur_node_a = cur_node_a->prev;
		if (cur_node_b)
			cur_node_b = cur_node_b->prev;
	}
	printf("-+--------------+-\t\t-+--------------+-\n");
}


