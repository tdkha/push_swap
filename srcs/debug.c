/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:56:14 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/07 16:24:40 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_debug_print_stack(t_stack *stack)
{
	t_index_node	*cur_node;
	
	cur_node = stack->top;
	if (!cur_node)
		ft_exit("No node in stack", 0);
	printf("Stack Size:\t%d\n", stack->size);
	printf("Stack Head:\t%d\n", stack->bot ? stack->bot->value : -42);
	printf("Stack top:\t%d\n", stack->top ? stack->top->value : -42);
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

void	ft_debug_print_stack_cluster(t_stack *stack)
{
	t_index_node	*cur_node;
	
	cur_node = stack->top;
	printf("Stack Size:\t%d\n", stack->size);
	printf("Stack Head:\t%d\n", stack->bot ? stack->bot->value : -42);
	printf("Stack top:\t%d\n", stack->top ? stack->top->value : -42);
	printf("-+--------------+-\n");
	while (cur_node)
	{
		printf(" |              | \n");
		printf(" |    %d [%d]     | \n", cur_node->value, cur_node->in_pair);
		printf(" |              | \n");
		cur_node = cur_node->prev;
	}
	printf("-+--------------+-\n");
}

void	ft_debug_print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_index_node	*cur_node_a;
	t_index_node	*cur_node_b;

	cur_node_a = stack_a->top;
	cur_node_b = stack_b->top;
	printf("Stack A Size:\t%d\t\tStack B Size:\t%d\n", stack_a->size, stack_b->size);
	printf("Stack A Head:\t%d\t\tStack B Head:\t%d\n", stack_a->bot ? stack_a->bot->value : -42, stack_b->bot ? stack_b->bot->value : -42);
	printf("Stack A top:\t%d\t\tStack B top:\t%d\n", stack_a->top ? stack_a->top->value : -42, stack_b->top ? stack_b->top->value : -42);
	printf("-+--------------+-\t\t-+--------------+-\n");

	while (cur_node_a || cur_node_b)
	{
		if (cur_node_a)
			printf(" |     %d[%d]     |", cur_node_a->origin, cur_node_a->in_pair);
		else
			printf(" |              |");
		printf("\t\t");
		if (cur_node_b)
			printf(" |     %d[%d]     |\n", cur_node_b->origin, cur_node_b->in_pair);
		else
			printf(" |              |\n");
		if (cur_node_a)
			cur_node_a = cur_node_a->prev;
		if (cur_node_b)
			cur_node_b = cur_node_b->prev;
	}
	printf("-+--------------+-\t\t-+--------------+-\n");
}


