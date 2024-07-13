/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_b2a_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:26:25 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/13 23:36:34 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algo.h"

/**
 * Function to check for existence of given <index> in range <size>
 */
int	index_inside_stack(
	t_stack *stack,
	int index,
	int size
)
{
	int				i;
	t_index_node	*node;

	i = 0;
	node = stack->top;
	while (i < size && node)
	{
		if (node->index == index)
			return (i);
		i++;
		node = node->prev;
	}
	return (-1);
}

int	a_contains_largest_sort_a(
	t_stack *a,
	int *unordered_top,
	int *unordered_bot,
	int highest
)
{
	if (!a || a->size == 0)
		return (0);
	if (index_inside_stack(a, highest, *unordered_top) != -1)
	{
		(*unordered_top)--;
		return (1);
	}
	else if (a->size && a->bot->index == highest)
	{
		printf("rra\n");
		ps_rrotate(a);
		(*unordered_bot)--;
		return (1);
	}
	return (0);
}

int	reorder_before_push(
	t_stack *a,
	t_stack *b,
	int *unordered_top,
	int *unordered_bot
)
{
	while (*unordered_top > 1)
	{
		ps_stack_action("ra", a, b);
		(*unordered_top)--;
		(*unordered_bot)++;
	}
	ps_stack_action("pa", a, b);
	if (*unordered_top == 1)
	{
		ps_stack_action("sa", a, b);
	}
}

int	push_almost_highest(
	t_stack *a,
	t_stack *b,
	int *unordered_top,
	int *unordered_bot
)
{
	if (!b->size)
		return (0);
	if (b->top->index < a->top->index
		&& (*unordered_bot == 0 || b->top->index > a->bot->index))
	{
		ps_stack_action("pa", a, b);
		(*unordered_top)++;
		return (1);
	}
	else if (*unordered_bot == 0 || b->top->index > a->bot->index)
	{
		while (*unordered_top && b->top->index > a->top->index)
		{
			ps_stack_action("ra", a, b);
			(*unordered_top)--;
			(*unordered_bot)++;
		}
		ps_stack_action("pa", a, b);
		(*unordered_top)++;
		return (1);
	}
	return (0);
}

int	rotate_b(
	t_stack *a,
	t_stack *b,
	int highest
)
{
	int	ihighest;

	ihighest = index_inside_stack(b, highest, b->size);
	if (ihighest == -1)
		return (0);
	if (ihighest < (b->size / 2))
	{
		ps_stack_action("rb", a, b);
		return (1);
	}
	else if (ihighest < b->size)
	{
		ps_stack_action("rrb", a, b);
		return (1);
	}
	return (0);
}
