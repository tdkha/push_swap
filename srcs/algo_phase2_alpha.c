/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_phase2_alpha.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:10:50 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/08 10:17:10 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"

/**
 * 	Top half elements are always larger that bot ones.
 * 		<1>	Look at top
 * 			a.	If min at top
 * 			b.	If max at top
 * 			c. 	Rotate irrelevent til either max or min found
 * 			d.	Add the number of rotate to the action stuct (reverse rotate later)
 * 		<2>	Look at the bottom 
 * 			if the top does not contain the current pair
 * 			a.	Find max at bot
 * 			b.	Reverse rotate until max at top 
 */

void	min_at_top()
{
	
}

void	max_at_top()
{

}

void	top_empty_look_bot()
{
	
}

void	phase2(t_data *data, t_stack *a, t_stack *b)
{
	t_actions		actions = {0};
	int				cur_pair;
	int				cur_pair_exist;
	
	cur_pair = data->max_pairs;
	while (cur_pair > 0)
	{
		cur_pair_exist = ft_pair_exist(b, cur_pair);
		if (cur_pair_exist > 0 || cur_pair != data->max_pairs)
			break ;
		cur_pair--;
	}
	while (cur_pair_exist > 0)
	{
		if (b->size == 0)
			break ;

		// logic goes here

		cur_pair_exist = ft_pair_exist(b, cur_pair);
		if (cur_pair_exist == 0 && cur_pair > 0)
		{
			cur_pair--;
			cur_pair_exist = ft_pair_exist(b, cur_pair);
		}
		ft_debug_print_stacks(a, b);
	}
}