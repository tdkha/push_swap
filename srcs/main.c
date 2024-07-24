/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:53:52 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/24 14:55:23 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	int			error;
	int			*sorted_array;
	t_data		general_data;
	t_stacks	stacks;

	general_data = (t_data){0};
	stacks.a = (t_stack){0};
	stacks.b = (t_stack){0};
	sorted_array = NULL;
	error = 0;
	if (ac == 1)
		return (0);
	ps_general_data_init(&general_data, ac, av);
	if (ft_arg_check(general_data.flat_av) == 0)
		error = 1;
	if (!error && !ft_init(&general_data, &sorted_array, &stacks.a, &stacks.b))
		error = 1;
	if (!error && ft_arg_parse(&general_data, sorted_array, &stacks.a))
		ps_sort(&general_data, &stacks.a, &stacks.b);
	else
	{
		ft_cleanup(&general_data, &sorted_array, &stacks, 1);
	}
	ft_cleanup(&general_data, &sorted_array, &stacks, 0);
	return (0);
}
