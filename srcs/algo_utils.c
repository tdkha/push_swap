/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:19 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/01 13:40:34 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"

void	ft_swap_num(int* a, int* b) 
{ 
	int	temp;

	temp = *a; 
	*a = *b; 
	*b = temp; 
} 

void	ft_swap_num_array(int *nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

static int	partition(int *arr, int left, int right)
{
	int	pivot_num;
	int	i;
	int	j;

	pivot_num = arr[left];
	i = left;
	j = right;
	while (i <= j)
	{
		while (i <= j && arr[i] <= pivot_num)
			i++;
		while (i <= j && arr[j] >= pivot_num)
			j--;
		if (i < j)
			ft_swap_num_array(arr, i, j);
	}
	ft_swap_num_array(arr, left, j);
	return j;
}

void	ft_quick_sort(int *arr, int left, int right)
{
	if (left < right)
	{
		int pivot_index = partition(arr, left, right);
		ft_quick_sort(arr, left, pivot_index - 1);
		ft_quick_sort(arr, pivot_index + 1, right);
	}
}

int	ps_stack_is_sorted(t_ps_stack  *stack)
{
	t_ps_node	*cur_node;

	cur_node = stack->head;
	while (cur_node)
	{
		if (cur_node->next && cur_node->value < cur_node->next->value)
			return(0);
		cur_node= cur_node->next;
	}
	return (1);
}