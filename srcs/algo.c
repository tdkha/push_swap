/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:47:16 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/04 15:31:51 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"
#include "../includes/push_swap.h"


void	ps_sort(t_data *data, t_stack *a, t_stack *b)
{
	if (a->size > 3)
	{
		phase1(data, a, b);
		ps_sort3(a);
		// phase2(data, a, b);
	}
	else
		ps_sort3(a);
}