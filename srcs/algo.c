/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:47:16 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/02 09:31:09 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"

void	ps_sort(t_ps_stack *a, t_ps_stack *b)
{
	if (a->max_clusters == 1)
	{
		ps_sort3(a);
	
	}
	else
	{
		ps_sort_large(a, b);
	}

}