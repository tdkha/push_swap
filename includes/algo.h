/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:30:26 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/07 16:33:10 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ALGO_H
# define ALGO_H

#include "../libft/libft.h"
#include "./stack.h"

/*+------------------------------------------------------------+*/
//	ALGO UTILS
/*+------------------------------------------------------------+*/

void	ft_swap_num(int* a, int* b);

void	ft_swap_num_array(int *nums, int i, int j);

void	ft_quick_sort(int *arr, int left, int right);

int		ps_stack_is_sorted(t_stack  *stack);

int		ft_pair_exist(t_stack *stack, int pair);

/*+------------------------------------------------------------+*/
//	ALGO UTILS
/*+------------------------------------------------------------+*/

int 	find_insert_pos_from_top(
			t_stack *a, 
			t_index_node *top_node,
			int cur_pair);
void	adjust_top(
			t_stack *a,
			t_stack *b,
			int iteration,
			t_index_node *pivot_node);

void	adjust_bot(
			t_stack *a,
			t_stack *b,
			int iteration,
			t_index_node *pivot_node);		
/*+------------------------------------------------------------+*/
//	ALGO SORT SMALL
/*+------------------------------------------------------------+*/

void	ps_sort3(t_stack *a, t_stack *b);

/*+------------------------------------------------------------+*/
//	ALGO SORT
/*+------------------------------------------------------------+*/

void	phase1(t_data *data, t_stack *a, t_stack *b);

void	phase2(t_data *data, t_stack *a, t_stack *b);

void	ps_sort(t_data *data, t_stack *a, t_stack *b);

#endif