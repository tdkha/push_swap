/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:53:52 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/28 13:20:43 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_ps_stack	stack;
	t_ps_node	*node;
	int			i = 0;

	ft_arg_check(ac, av);
	stack = ps_stack_init();
	while (i < 3)
	{
		node = ps_node_init(i);
		ps_stack_push(&stack, node);
		i++;
	}
	ps_stack_cluster_divide(&stack);
	// ft_debug_print_stack(&stack);
	// ps_rotate(&stack);
	// ft_debug_print_stack(&stack);
	// ps_rrotate(&stack);
	// ft_debug_print_stack(&stack);
	ps_stack_free(&stack);
	return (0);	
}
