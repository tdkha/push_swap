/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:30:26 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/02 11:38:55 by ktieu            ###   ########.fr       */
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

int		ps_stack_is_sorted(t_ps_stack  *stack);


/*+------------------------------------------------------------+*/
//	ALGO SORT LARGE UTILS
/*+------------------------------------------------------------+*/

int		maintain_three_highest(t_ps_stack *stack);
int 	check_to_push(t_ps_stack *stack, int cluster1, int cluster2);
void	ps_sort_large(t_ps_stack *a, t_ps_stack *b);

/*+------------------------------------------------------------+*/
//	ALGO SORT SMALL
/*+------------------------------------------------------------+*/

void	ps_sort3(t_ps_stack *a);
void 	ps_sort4(t_ps_stack *a, t_ps_stack *b);

/*+------------------------------------------------------------+*/
//	ALGO SORT
/*+------------------------------------------------------------+*/

void	ps_sort(t_ps_stack *a, t_ps_stack *b);

#endif