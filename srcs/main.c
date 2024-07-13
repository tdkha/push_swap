/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:53:52 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/13 23:53:28 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Program parsing function
 * Description: 
 *	<1> First parse the <arg> to an array.
 *	<2> Then use that array to parse a <node> for a <stack>
 */
static int	ft_arg_parse(
	t_data *general_data,
	int *arr, t_stack *stack)
{
	if (ft_arg_parse_to_arr(general_data, arr) == NULL)
		return (0);
	if (ft_arg_parse_to_stack(general_data, arr, stack) == NULL)
		return (0);
	return (1);
}

static inline int	ft_init(
	t_data *general_data,
	int **array,
	t_stack *a,
	t_stack *b)
{
	*array = (int *) malloc (sizeof(int) * (general_data->ac - 1));
	if (!(*array))
		return (0);
	*a = ps_stack_init();
	*b = ps_stack_init();
	return (1);
}

static inline void	ft_cleanup(int **array, t_stack *a, t_stack *b)
{
	if (*array)
	{
		free(*array);
		*array = NULL;
	}
	if (a != NULL)
		ps_stack_free(a);
	if (b != NULL)
		ps_stack_free(b);
}

static void	ft_parse_general_data(
	t_data *general_data,
	int ac,
	char **av
)
{
	general_data->ac = ac;
	general_data->av = av;
	if (ac - 1 <= 20)
		general_data->max_chunks = 1;
	else if (ac - 1 <= 100)
		general_data->max_chunks = 4;
	else
		general_data->max_chunks = 10;
	general_data->total_amt = ac - 1;
}

int	main(int ac, char **av)
{
	int		error;
	int		*sorted_array;
	t_data	general_data;
	t_stack	stack_a = {0};
	t_stack	stack_b = {0};

	sorted_array = NULL;
	error = 0;
	if (ac == 1)
		return (0);
	ft_parse_general_data(&general_data, ac, av);
	if (ft_arg_check(ac, av) == 0)
		error = 1;
	if (!error && !ft_init(&general_data, &sorted_array, &stack_a, &stack_b))
		error = 1;
	if (!error && ft_arg_parse(&general_data, sorted_array, &stack_a))
		ps_sort(&general_data, &stack_a, &stack_b);
	else
	{
		ft_cleanup(&sorted_array, &stack_a, &stack_b);
		ft_exit("Error", 1);
	}
	ft_cleanup(&sorted_array, &stack_a, &stack_b);
	return (0);
}
