/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:16:58 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/16 12:36:11 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Program parsing function
 * Description: 
 *	<1> First parse the <arg> to an array.
 *	<2> Then use that array to parse a <node> for a <stack>
 */
int	ft_arg_parse(
	t_data *general_data,
	int *arr, t_stack *stack)
{
	if (ft_arg_parse_to_arr(general_data, arr) == NULL)
		return (0);
	if (ft_arg_parse_to_stack(general_data, arr, stack) == NULL)
		return (0);
	return (1);
}

inline int	ft_init(
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

inline void	ft_cleanup(
	t_data *data,
	int **array,
	t_stacks *stacks,
	int early_exit)
{
	if (*array)
	{
		free(*array);
		*array = NULL;
	}
	ft_multiple_free_set_null(&data->flat_av);
	if (&(stacks->a) != NULL)
		ps_stack_free(&(stacks->a));
	if (&(stacks->a) != NULL)
		ps_stack_free(&(stacks->a));
	if (early_exit)
		ft_exit("Error", 1);
}

inline void	ft_cleanup_bonus(
	t_data *data,
	int **array,
	t_stacks *stacks,
	int code)
{
	if (*array)
	{
		free(*array);
		*array = NULL;
	}
	ft_multiple_free_set_null(&data->flat_av);
	if (&(stacks->a) != NULL)
		ps_stack_free(&(stacks->a));
	if (&(stacks->a) != NULL)
		ps_stack_free(&(stacks->a));
	if (code == -1)
		ft_exit("KO", 0);
	else if (code == 0)
		ft_exit("OK", 0);
	else if (code == 1)
		ft_exit("Error", 1);
}
