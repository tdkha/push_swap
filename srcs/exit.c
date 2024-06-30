/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:39:35 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/30 14:51:56 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Function called to exit the program after printing the messaage
 * @param msg {char *}
 * @param exitcode {int}
 */
void	ft_exit(char *msg, int exitcode)
{
	if (!msg || !(*msg))
		exit(exitcode);
	if (exitcode != 0)
		ft_printf_fd(2, "push_swap: %s\n", msg);
	else
		ft_printf("push_swap: %s\n", msg);
	exit(exitcode);
}
