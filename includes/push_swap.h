/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:54:23 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/24 14:54:54 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./stack.h"
# include "./algo.h"

void		ps_general_data_init(
				t_data *general_data,
				int ac,
				char **av);

int			ft_init(
				t_data *general_data,
				int **array,
				t_stack *a,
				t_stack *b);

int			ft_arg_parse(
				t_data *general_data,
				int *arr, t_stack *stack);

void		ft_cleanup(
				t_data *data,
				int **array,
				t_stacks *stacks,
				int early_exit);

void		ft_cleanup_bonus(
				t_data *data,
				int **array,
				t_stacks *stacks,
				int code);
/*+------------------------------------------------------------+*/
//	Argument check
/*+------------------------------------------------------------+*/

int			ft_arg_check_dup(int *sorted_arr, int size);
int			ft_arg_check(char **av);

/*+------------------------------------------------------------+*/
//	Argument parsing
/*+------------------------------------------------------------+*/

int			*ft_arg_parse_to_arr(t_data *general_data, int *arr);
t_stack		*ft_arg_parse_to_stack(
				t_data *general_data,
				int *arr,
				t_stack *stack);

/*+------------------------------------------------------------+*/
//	Program util functions
/*+------------------------------------------------------------+*/
void		ft_exit(char *msg, int exitcode);

#endif