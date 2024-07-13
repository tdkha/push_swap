/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:19 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/13 23:55:16 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"

void	ft_swap_num(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_swap_num_array(int *nums, int i, int j)
{
	int	tmp;

	tmp = nums[i];
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
	return (j);
}

void	ft_quick_sort(int *arr, int left, int right)
{
	int	pivot_index;

	if (left < right)
	{
		pivot_index = partition(arr, left, right);
		ft_quick_sort(arr, left, pivot_index - 1);
		ft_quick_sort(arr, pivot_index + 1, right);
	}
}
