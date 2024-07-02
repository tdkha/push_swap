/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:03:49 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/03 00:38:22 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*ft_arg_parse_to_arr(int ac, char **av, int *arr)
{
	int	i;

	i = 1;
	if (ac < 2)
		return (NULL);
	while (i < ac)
	{
		arr[i - 1] = ft_atoi(av[i]);
		i++;
	}
	ft_quick_sort(arr, 0, i - 2);
	return (arr);
}

/**
 * Function to define whihc cluster a node belongs to
 * Description:
 * 	<1>	Calculate the range of the first 2 clusters, the rest will be the cluster3's range.
 * 	<2> Find the <node> from a sorted array. Then get the index of the array element.
 * 	<3> See where the index falls in the range among clusters.
 * 	<4> Return the cluster.
 */
// static inline int	ps_define_cluster(int *array, int arr_size, t_index_node *node, t_stack *stack)
// {
// 	int	max_amount;
// 	int	index_in_cluster_range;
// 	int	i;

// 	i = 0;
// 	max_amount = arr_size / stack->max_clusters;
// 	while (i < arr_size)
// 	{
// 		if (node->value == array[i])
// 			break;
// 		i++;
// 	}
// 	index_in_cluster_range = i + 1;
// 	for (int cluster = 1; cluster <= stack->max_clusters; cluster++)
// 	{
// 		if (index_in_cluster_range <= cluster * max_amount)
// 			return cluster;
// 	}
// 	return stack->max_clusters;
// }


// static inline void ft_calculate_cluster_ranges(int ac, t_stack *stack)
// {
// 	int	array_size;
// 	int	max_amount;

// 	max_amount = 20;
// 	array_size = ac - 1;

// 	if (array_size <= 3)
// 		stack->max_clusters = 1;
// 	else if (array_size <= 10)
// 		stack->max_clusters = 2;
// 	else if (array_size <= 20)
// 		stack->max_clusters = 4;
// 	else
// 		stack->max_clusters = 6;
// }


static inline void ft_to_index(
	int *arr, 
	t_stack *stack,
	t_index_node *node)
{
	int per_pair;
	int	found_index;
	int	scaler;
	int range;

	scaler = 1;
	found_index = 0;
	per_pair = stack->size / (stack->pairs);
	while (found_index < stack->size)
	{
		if (arr[found_index] == node->value)
			break ;
		found_index++;
	}
	found_index++;
	range = scaler * (per_pair);
	while (found_index > range)
	{
		scaler++;
		range = scaler * (per_pair);
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
t_stack	*ft_arg_parse_to_stack(int ac, char **av, int *arr, t_stack *stack)
{
	int		i;
	t_index_node	*node;
	
	node = NULL;
	i = 1;
	if (ac < 2)
		return (NULL);
	while (i < ac)
	{
		node = ps_node_init(ft_atoi(av[i]));
		ft_to_index(arr, stack, node);
		ps_stack_push(stack, node);
		i++;
	}
	return (stack);
}
