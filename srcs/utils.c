/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:16:58 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/15 09:26:18 by ktieu            ###   ########.fr       */
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
	int **array,
	t_stack *a,
	t_stack *b,
	int early_exit)
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
	if (early_exit)
		ft_exit("Error", 1);
}

inline void	ft_cleanup_bonus(
	int **array,
	t_stack *a,
	t_stack *b,
	int code)
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
	if (code == -1)
		ft_exit("KO", 0);
	else if (code == 0)
		ft_exit("OK", 0);
	else if (code == 1)
		ft_exit("Error", 1);
}

void	ps_general_data_init(
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
