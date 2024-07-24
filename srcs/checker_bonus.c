/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:07:17 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/24 14:55:03 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static int	check_sorted(
	t_stack *a,
	t_stack *b
)
{
	int	status;

	if (b->size >= 1)
		return (0);
	status = ps_stack_is_sorted(a);
	return (status);
}

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
			if (str)
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
	int			error;
	int			*sorted_array;
	t_data		data;
	t_stacks	stacks;

	stacks.a = (t_stack){0};
	stacks.b = (t_stack){0};
	sorted_array = NULL;
	error = 0;
	if (ac < 2)
		return (0);
	ps_general_data_init(&data, ac, av);
	if (ft_arg_check(data.flat_av) == 0)
		error = 1;
	if (!error && !ft_init(&data, &sorted_array, &stacks.a, &stacks.b))
		error = 1;
	if (!error && !ft_arg_parse(&data, sorted_array, &stacks.a))
		error = 1;
	if (!error && reader(&stacks.a, &stacks.b) == 0)
		error = 1;
	if (!error && check_sorted(&stacks.a, &stacks.b) == 0)
		error = -1;
	ft_cleanup_bonus(&data, &sorted_array, &stacks, error);
	return (0);
}
