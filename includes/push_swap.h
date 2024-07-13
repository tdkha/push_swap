/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:54:23 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/13 20:04:27 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./stack.h"
#include "./algo.h"

/*+------------------------------------------------------------+*/
//	Argument check
/*+------------------------------------------------------------+*/
void		ft_arg_check(int ac, char **av);

/*+------------------------------------------------------------+*/
//	Argument parsing
/*+------------------------------------------------------------+*/
void		ft_parse_general_data(
				t_data *general_data,
				int ac,
				char **av);
int			*ft_arg_parse_to_arr(t_data *general_data, int *arr);
t_stack		*ft_arg_parse_to_stack(t_data *general_data, int *arr, t_stack *stack);
/*+------------------------------------------------------------+*/
//	Program util functions
/*+------------------------------------------------------------+*/
void		ft_exit(char *msg, int exitcode);

#endif