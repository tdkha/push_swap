/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:34:35 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/29 16:03:59 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static inline int ft_arg_check_type(char *str, int i, int sign)
{
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!str[i] || !ft_isdigit(str[i]))
		return (0);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

inline void	ft_arg_check(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 2)
	{
		ft_printf_fd(2, "Error\n");
		exit(1);
	}
	while (i < ac)
	{
		if (ft_arg_check_type(av[i], 0 ,1) == 0)
		{
			ft_printf_fd(2, "Error\n");
			exit(1);
		}
		i++;
	}
}
