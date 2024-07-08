/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:47:16 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/07 22:19:00 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"
#include "../includes/push_swap.h"


void	ps_sort(t_data *data, t_stack *a, t_stack *b)
{
	if (data->total > 3)
	{
		phase1(data, a, b);
		ps_sort3(a, b);
		// ft_debug_print_stacks(a,b);
		phase2(data, a, b);
	}
	else if (data->total == 3)
		ps_sort3(a, b);
}