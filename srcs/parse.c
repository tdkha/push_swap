/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:03:49 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/04 14:41:49 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	return (arr);
}

void	ft_parse_general_data(t_data *data, int size)
{
	data->max_pairs = 3;
	data->amt_per_pair = (size + 1) / data->max_pairs;
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
		if (arr[found_index] == node->value)
			break ;
		found_index++;
	}
	node->value = found_index;
	found_index++;
	range = scaler * (data->amt_per_pair);
	while (found_index > range)
	{
		scaler++;
		if (scaler > data->max_pairs)
		{
			scaler = data->max_pairs;
			break;
		}
		range = scaler * (data->amt_per_pair);
	}
	node->in_pair = scaler;
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
	i = 1;
	if (general_data->ac < 2)
		return (NULL);
	while (i <general_data->ac)
	{
		node = ps_node_init(ft_atoi(general_data->av[i]));
		if (!node)
		{
			ps_stack_free(stack);
			ft_printf_fd(2, "push_swap: Failed to malloc <t_index_node>\n");
			return (NULL);
		}
		ps_stack_push(stack, node);
		i++;
	}
	node = stack->top;
	general_data->amt_per_pair = (stack->size + 1) / (general_data->max_pairs);
	while (node)
	{
		ft_to_index(general_data, arr, stack, node);
		node = node->prev;
	}
	return (stack);
}
