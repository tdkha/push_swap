/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:53:52 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/26 16:51:59 by ktieu            ###   ########.fr       */
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

static inline void	ft_arg_check(int ac, char **av)
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

int	main(int ac, char **av)
{
	t_ps_stack	stack;
	t_ps_node	*node;
	int			i = 0;

	ft_arg_check(ac, av);
	stack = ps_stack_init();
	while (i < 3)
	{
		node = ps_node_init(i);
		ps_stack_push(&stack, node);
		i++;
	}
	ft_debug_print_stack(&stack);
	ps_swap(&stack);
	ft_debug_print_stack(&stack);
	ps_stack_free(&stack);
	return (0);	
}
