/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:34:55 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/14 17:48:31 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static int	do_push(char c, t_stack *a, t_stack *b)
{
	int	res;

	res = 1;
	if (c == 'a')
	{
		ps_push(b, a);
	}
	else if (c == 'b')
	{
		ps_push(a, b);
	}
	else
		res = 0;
	return (res);
}

static int	do_swap(char c, t_stack *a, t_stack *b)
{
	int	res;

	res = 1;
	if (c == 'a')
	{
		res = ps_swap(a);
	}
	else if (c == 'b')
	{
		res = ps_swap(b);
	}
	else if (c == 's')
	{
		if (ps_swap(a) && ps_swap(b))
			res = 1;
		else
			res = 0;
	}
	else
		res = 0;
	return (res);
}

static int	do_rotate(char c, t_stack *a, t_stack *b)
{
	int	res;

	res = 1;
	if (c == 'a')
	{
		res = ps_rotate(a);
	}
	else if (c == 'b')
	{
		res = ps_rotate(b);
	}
	else if (c == 'r')
	{
		res = ps_rotate2(a, b);
	}
	else
		res = 0;
	return (res);
}

static int	do_reverse_rotate(char c, t_stack *a, t_stack *b)
{
	int	res;

	res = 1;
	if (c == 'a')
	{
		res = ps_rrotate(a);
	}
	else if (c == 'b')
	{
		res = ps_rrotate(b);
	}
	else if (c == 'r')
	{
		res = ps_rrotate2(a, b);
	}
	else
		res = 0;
	return (res);
}

int	ps_stack_action_bonus(char *str, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(str, "sa\n", 3))
		return (do_swap('a', a, b));
	else if (!ft_strncmp(str, "sb\n", 3))
		return (do_swap('b', a, b));
	else if (!ft_strncmp(str, "ss\n", 3))
		return (do_swap('s', a, b));
	else if (!ft_strncmp(str, "pa\n", 3))
		return (do_push('a', a, b));
	else if (!ft_strncmp(str, "pb\n", 3))
		return (do_push('b', a, b));
	else if (!ft_strncmp(str, "ra\n", 3))
		return (do_rotate('a', a, b));
	else if (!ft_strncmp(str, "rb\n", 3))
		return (do_rotate('b', a, b));
	else if (!ft_strncmp(str, "rr\n", 3))
		return (do_rotate('r', a, b));
	else if (!ft_strncmp(str, "rra\n", 4))
		return (do_reverse_rotate('a', a, b));
	else if (!ft_strncmp(str, "rrb\n", 4))
		return (do_reverse_rotate('b', a, b));
	else if (!ft_strncmp(str, "rrr\n", 4))
		return (do_reverse_rotate('r', a, b));
	else
		return (0);
}
