/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:40:51 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/15 09:22:06 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static int	do_push(char c, t_stack *a, t_stack *b)
{
	int	res;

	res = 1;
	if (c == 'a')
	{
		res = ps_push(b, a);
		if (res)
			ft_printf("pa\n");
	}
	else if (c == 'b')
	{
		res = ps_push(a, b);
		if (res)
			ft_printf("pb\n");
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
		if (res)
			ft_printf("sa\n");
	}
	else if (c == 'b')
	{
		res = ps_swap(b);
		if (res)
			ft_printf("sb\n");
	}
	else if (c == 's')
	{
		if (ps_swap(a) && ps_swap(b))
			ft_printf("ss\n");
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
		if (res)
			ft_printf("ra\n");
	}
	else if (c == 'b')
	{
		res = ps_rotate(b);
		if (res)
			ft_printf("rb\n");
	}
	else if (c == 'r')
	{
		res = ps_rotate2(a, b);
		if (res)
			ft_printf("rr\n");
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
		if (res)
			ft_printf("rra\n");
	}
	else if (c == 'b')
	{
		res = ps_rrotate(b);
		if (res)
			ft_printf("rrb\n");
	}
	else if (c == 'r')
	{
		if (ps_rrotate2(a, b))
			ft_printf("rrr\n");
		else
			res = 0;
	}
	else
		res = 0;
	return (res);
}

int	ps_stack_action(char *str, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(str, "sa", 3))
		return (do_swap('a', a, b));
	else if (!ft_strncmp(str, "sb", 3))
		return (do_swap('b', a, b));
	else if (!ft_strncmp(str, "ss", 3))
		return (do_swap('s', a, b));
	else if (!ft_strncmp(str, "pa", 3))
		return (do_push('a', a, b));
	else if (!ft_strncmp(str, "pb", 3))
		return (do_push('b', a, b));
	else if (!ft_strncmp(str, "ra", 3))
		return (do_rotate('a', a, b));
	else if (!ft_strncmp(str, "rb", 3))
		return (do_rotate('b', a, b));
	else if (!ft_strncmp(str, "rr", 3))
		return (do_rotate('r', a, b));
	else if (!ft_strncmp(str, "rra", 4))
		return (do_reverse_rotate('a', a, b));
	else if (!ft_strncmp(str, "rrb", 4))
		return (do_reverse_rotate('b', a, b));
	else if (!ft_strncmp(str, "rrr", 4))
		return (do_reverse_rotate('r', a, b));
	else
		return (0);
}
