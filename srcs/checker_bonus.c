/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:07:17 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/15 10:54:35 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static int	reader(
	t_stack *a,
	t_stack *b
)
{
	char	*str;

	str = get_next_line(STDIN_FILENO);
	while (str)
	{
		if (!ps_stack_action_bonus(str, a, b))
		{
			if(str)
				free(str);
			return (0);
		}
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		error;
	int		*sorted_array;
	t_data	data;
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a = (t_stack){0};
	stack_b = (t_stack){0};
	sorted_array = NULL;
	error = 0;
	if (ac < 2)
		return (0);
	ps_general_data_init(&data, ac, av);
	if (ft_arg_check(ac, av) == 0)
		error = 1;
	if (!error && !ft_init(&data, &sorted_array, &stack_a, &stack_b))
		error = 1;
	if (!error && !ft_arg_parse(&data, sorted_array, &stack_a))
		error = 1;
	if (!error && reader(&stack_a, &stack_b) == 0)
		error = 1;
	if (!error && ps_stack_is_sorted(&stack_a) == 0)
		error = -1;
	ft_cleanup_bonus(&sorted_array, &stack_a, &stack_b, error);
	return (0);
}
