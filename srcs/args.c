/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:34:35 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/13 21:00:47 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


static int	check_valid_num(const char *str)
{
	long long int	res;
	int				sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if (res > 2147483647 || res < -2147483647 - 1)
			return (0);
	return (1);
}

static inline int ft_arg_check_type(
	char *str,
	int i,
	int sign)
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
	if (str[i] == '0')
	{
		i++;
		if (str[i] && ft_isdigit(str[i]))
			return (0);
	}
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

inline int	ft_arg_check(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		if (!ft_arg_check_type(av[i], 0 ,1))
			return (0);
		if (!check_valid_num(av[i]))
			return (0);
		i++;
	}
	return (1);
}
