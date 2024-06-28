/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:19 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/28 13:32:17 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"

void	swap(int* a, int* b) 
{ 
	int	temp;

	temp = *a; 
	*a = *b; 
	*b = temp; 
} 