/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:53:52 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/14 15:39:23 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	int		error;
	int		*sorted_array;
	t_data	general_data;
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a = (t_stack){0};
	stack_b = (t_stack){0};
	sorted_array = NULL;
	error = 0;
	if (ac == 1)
		return (0);
	ps_general_data_init(&general_data, ac, av);
	if (ft_arg_check(ac, av) == 0)
		error = 1;
	if (!error && !ft_init(&general_data, &sorted_array, &stack_a, &stack_b))
		error = 1;
	if (!error && ft_arg_parse(&general_data, sorted_array, &stack_a))
		ps_sort(&general_data, &stack_a, &stack_b);
	else
	{
		ft_cleanup(&sorted_array, &stack_a, &stack_b, 1);
	}
	ft_cleanup(&sorted_array, &stack_a, &stack_b, 0);
	return (0);
}
