/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:40:51 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/06 15:56:51 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static int do_push(char c, t_stack *a, t_stack *b)
{
	int res;

	res = 1;
	if (c == 'a')
	{
		printf("pa\n");
		ps_push(b, a);
	}
	else if (c == 'b')
	{
		printf("pb\n");
		ps_push(a, b);
	}
	else
		res = 0;
	return (res);
}

static int do_swap(char c, t_stack *a, t_stack *b)
{
	int res;

	res = 1;
	if (c == 'a')
	{
		printf("sa\n");
		ps_swap(a);
	}
	else if (c == 'b')
	{
		printf("sb\n");
		ps_swap(b);
	}
	else if (c == 's')
	{
		printf("ss\n");
		ps_swap(a);
		ps_swap(b);
	}
	else
		res = 0;
	return (res);
}

static int do_rotate(char c, t_stack *a, t_stack *b)
{
	int res;

	res = 1;
	if (c == 'a')
	{
		printf("ra\n");
		ps_rotate(a);
	}
	else if (c == 'b')
	{
		printf("rb\n");
		ps_rotate(b);
	}
	else if (c == 'r')
	{
		printf("rr\n");
		ps_rotate2(a, b);
	}
	else
		res = 0;
	return (res);
}

static int do_reverse_rotate(char c, t_stack *a, t_stack *b)
{
	int res;

	res = 1;
	if (c == 'a')
	{
		printf("rra\n");
		ps_rrotate(a);
	}
	else if (c == 'b')
	{
		printf("rrb\n");
		ps_rrotate(b);
	}
	else if (c == 'r')
	{
		printf("rrr\n");
		ps_rrotate(a);
		ps_rrotate(b);
	}
	else
		res = 0;
	return (res);
}

void ps_stack_action(char *str, t_stack *a, t_stack *b)
{
	int res;

	res = 0;
	if (str[0] == 'r')
	{
		if (str[1] == 'r' && str[2] != '\0')
			res = do_reverse_rotate(str[2], a, b);
		else
			res = do_rotate(str[1], a, b);
	}
	else if (str[0] == 's')
		res = do_swap(str[1], a, b);
	else if (str[0] == 'p')
		res = do_push(str[1], a, b);
	else
		res = 0;
	if (res == 0)
		printf("push_swap: %s: Invalid action to stack\n", str);
}
