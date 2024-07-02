/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:47:16 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/03 00:53:38 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"


void	phase1(t_stack *a, t_stack *b)
{
	printf("Phase 1\n");
}


void	ps_sort(t_stack *a, t_stack *b)
{
	if (a->size > 3)
	{
		phase1(a, b);
	}
	else
		ps_sort3(a);
	
}