/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:03:49 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/13 20:07:41 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static inline int	ft_arg_check_dup(int *sorted_arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (sorted_arr[i] == sorted_arr[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	*ft_arg_parse_to_arr(t_data *general_data, int *arr)
{
	int	i;

	i = 1;
	if (general_data->ac < 2)
		return (NULL);
	while (i < general_data->ac)
	{
		arr[i - 1] = ft_atoi(general_data->av[i]);
		i++;
	}
	ft_quick_sort(arr, 0, i - 2);
	if (!ft_arg_check_dup(arr, general_data->ac - 1))
	{
		return (NULL);
	}
	return (arr);
}

void	ft_parse_general_data(
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

/**
 * Use the existing <value> property to find the index in the sorted array
 * Replace the <value> by the index
 * Search for whihch pair the index belongs to
 */
static void ft_to_index(
	t_data *data,
	int *arr, 
	t_stack *stack,
	t_index_node *node)
{
	int	found_index;
	int	scaler;
	int range;

	scaler = 1;
	found_index = 0;
	while (found_index < stack->size)
	{
		if (arr[found_index] == node->index)
			break ;
		found_index++;
	}
	node->index = found_index;
}

/**
 * Parse program arguments to a stack.
 * Description:
 * 	<1> Create a node.
 * 	<2> Define which cluster the node belongs to (among 1, 2, 3)
 * 	<3> Push the created node to the stack 
 * @param ac {int} argument count
 * @param av {char **} argument vector
 * @param arr {int *} an array
 * @param stack {t_stack} a stack
 */
t_stack	*ft_arg_parse_to_stack(t_data *general_data, int *arr, t_stack *stack)
{
	int				i;
	t_index_node	*node;
	
	node = NULL;
	i = general_data->ac - 1;
	if (general_data->ac < 2)
		return (NULL);
	while (i > 0)
	{
		node = ps_node_init(ft_atoi(general_data->av[i]));
		if (!node)
		{
			return (NULL);
		}
		ps_stack_push(stack, node);
		i--;
	}
	node = stack->top;
	general_data->amt_per_chunk = (stack->size + 1) / (general_data->max_chunks);
	while (node)
	{
		ft_to_index(general_data, arr, stack, node);
		node = node->prev;
	}
	return (stack);
}
