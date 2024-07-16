/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:03:49 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/16 13:00:01 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

inline int	ft_arg_check_dup(int *sorted_arr, int size)
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
		arr[i - 1] = ft_atoi(general_data->flat_av[i]);
		i++;
	}
	ft_quick_sort(arr, 0, i - 2);
	if (!ft_arg_check_dup(arr, general_data->ac - 1))
	{
		return (NULL);
	}
	return (arr);
}

/**
 * Use the existing <value> property to find the index in the sorted array
 * Replace the <value> by the index
 * Search for whihch pair the index belongs to
 */
static void	ft_to_index(
	int *arr,
	t_stack *stack,
	t_index_node *node)
{
	int	found_index;

	found_index = 0;
	while (found_index < stack->size)
	{
		if (arr[found_index] == node->index)
			break ;
		found_index++;
	}
	node->index = found_index;
}

static void	convert_num_to_index(int *arr, t_stack *stack)
{
	t_index_node	*node;

	node = stack->top;
	while (node)
	{
		ft_to_index(arr, stack, node);
		node = node->prev;
	}
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
t_stack	*ft_arg_parse_to_stack(t_data *data, int *arr, t_stack *stack)
{
	int				i;
	t_index_node	*node;

	node = NULL;
	i = data->ac - 1;
	if (data->ac < 2)
		return (NULL);
	while (i > 0)
	{
		node = ps_node_init(ft_atoi(data->flat_av[i]));
		if (!node)
		{
			ps_stack_free(stack);
			return (NULL);
		}
		ps_stack_push(stack, node);
		i--;
	}
	data->amt_per_chunk = (stack->size + 1) / (data->max_chunks);
	convert_num_to_index(arr, stack);
	return (stack);
}
