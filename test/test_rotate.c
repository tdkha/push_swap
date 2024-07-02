/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:33:26 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/03 00:33:24 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack;
	t_index_node	*node;
	int			i = 0;

	ft_arg_check(ac, av);
	stack = ps_stack_init(ac - 1);
	while (i < 3)
	{
		node = ps_node_init(i);
		ps_stack_push(&stack, node);
		i++;
	}
	ft_debug_print_stack(&stack);
	ps_rotate(&stack);
	ft_debug_print_stack(&stack);
	ps_rrotate(&stack);
	ft_debug_print_stack(&stack);
	ps_stack_free(&stack);
	return (0);	
}
