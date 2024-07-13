/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:53:52 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/13 20:04:35 by ktieu            ###   ########.fr       */
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
	*array = (int *) malloc (sizeof(int) * (general_data->ac- - 1));
	if (!(*array))
		return (0);
	*a = ps_stack_init();
	*b = ps_stack_init();
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

int	main(int ac, char **av)
{
	int		*sorted_array;
	t_data	general_data;
	t_stack	stack_a;
	t_stack	stack_b;
	t_index_node	*node;

	ft_arg_check(ac, av);
	ft_parse_general_data(&general_data, ac, av);
	if (!ft_init(&general_data, &sorted_array, &stack_a, &stack_b))
	{
		ft_cleanup(&sorted_array, &stack_a, &stack_b);
		ft_exit("Error", 1);
	}
	if (ft_arg_parse(&general_data, sorted_array, &stack_a))
		ps_sort(&general_data, &stack_a, &stack_b);
	else
		ft_printf("Error\n");
	ft_cleanup(&sorted_array, &stack_a, &stack_b);
	return (0);	
}
