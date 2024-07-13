/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:30:26 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/13 20:56:27 by ktieu            ###   ########.fr       */
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

void	a2b_update_chunk(
			t_data *data,
			t_chunk *chunk,
			t_stack *a);

int		index_in_range(
			int index,
			int min,
			int max);

t_chunk	a2b_chunk_init(t_data *data, t_stack *a);

/*+------------------------------------------------------------+*/
//	B2A UTILS
/*+------------------------------------------------------------+*/

int		index_inside_stack(
			t_stack *stack,
			int	index,
			int size);

int		a_contains_largest_sort_a(
			t_stack *a,
			int *unordered_top,
			int *unordered_bot,
			int	highest);

int		reorder_before_push(
			t_stack *a,
			t_stack *b,
			int *unordered_top,
			int *unordered_bot);

int		push_almost_highest(
			t_stack *a,
			t_stack *b,
			int *unordered_top,
			int *unordered_bot);

int		rotate_b(
			t_stack *a,
			t_stack *b,
			int highest);
/*+------------------------------------------------------------+*/
//	ALGO SORT
/*+------------------------------------------------------------+*/

void	ps_sort3(t_stack *a, t_stack *b);
void	ps_sort(t_data *data, t_stack *a, t_stack *b);

#endif