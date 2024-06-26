/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:56:14 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/26 16:53:21 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_debug_print_stack(t_ps_stack *stack)
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
		printf(" |      %d       | \n", cur_node->value);
		printf(" |              | \n");
		cur_node = cur_node->prev;
	}
	printf("-+--------------+-\n");
}

void	ft_debug_print_stacks(t_ps_stack *stack_a, t_ps_stack *stack_b )
{
	ft_debug_print_stack(stack_a);
	ft_debug_print_stack(stack_b);
}
