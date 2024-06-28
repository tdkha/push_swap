/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:47:16 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/28 14:47:50 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"

static inline int partition(int *arr, int left, int right)
{
	int	i;
	int	j;

	i = left;
	j = right;
	while (i < j)
	{
		
	}
}

void	quick_sort(int *arr, int left, int right)
{
	int	pivot;

	if (left >= right)
		return ;
	pivot = partition(arr, left, right);
	
}