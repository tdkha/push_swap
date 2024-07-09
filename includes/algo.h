/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:30:26 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/09 19:04:48 by ktieu            ###   ########.fr       */
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


/*+------------------------------------------------------------+*/
//	A2B UTILS
/*+------------------------------------------------------------+*/

int		chunk_check_index_exist(
			t_data * data,
			t_chunk *chunk,
			t_stack *a);

void	update_chunk(
			t_data * data,
			t_chunk *chunk);

int		index_in_range(
			int index,
			int min,
			int max);

t_chunk	a2b_chunk_init(t_data *data, t_stack *a);

/*+------------------------------------------------------------+*/
//	B2A UTILS
/*+------------------------------------------------------------+*/

int		distance_from_top(
			int to_find,
			t_stack *b);

int		distance_from_bot(
			int to_find,
			t_stack *b);

/*+------------------------------------------------------------+*/
//	ALGO SORT
/*+------------------------------------------------------------+*/

void	ps_sort3(t_stack *a, t_stack *b);
void	ps_sort(t_data *data, t_stack *a, t_stack *b);

#endif