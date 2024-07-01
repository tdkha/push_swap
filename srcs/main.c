/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:53:52 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/01 16:27:43 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Program parsing function
 * Description: 
 *	<1> First parse the <arg> to an array.
 *	<2> Then use that array to parse a <node> for a <stack>
 */
static inline void	ft_arg_parse(int ac, char **av, int *arr, t_ps_stack *stack)
{
	ft_arg_parse_to_arr(ac, av, arr);
	ft_arg_parse_to_stack(ac, av, arr, stack);
}

static inline void	ft_init(int ac, int **array, t_ps_stack *a, t_ps_stack *b)
{
	*array = (int *) malloc (sizeof(int) * (ac - 1));
	if (!(*array))
		ft_exit("Failed to malloc an array in main function", 1);
	*a = ps_stack_init();
	*b = ps_stack_init();
}

static inline void	ft_cleanup(int *array, t_ps_stack *a, t_ps_stack *b)
{
	if (array)
		free(array);
	if (a != NULL)
		ps_stack_free(a);
	if (b != NULL)
		ps_stack_free(b);
}

int	main(int ac, char **av)
{
	int			*sorted_array;
	t_ps_stack	stack_a;
	t_ps_stack	stack_b;
	t_ps_node	*node;


	ft_arg_check(ac, av);
	ft_init(ac, &sorted_array, &stack_a, &stack_b);
	ft_arg_parse(ac, av, sorted_array, &stack_a);
	ft_debug_print_stacks(&stack_a, &stack_b);

	printf("Array: ");
	for (int j = 0; j < stack_a.size; j++)
	{
		printf("%d ", sorted_array[j]);
	}
	printf("\n");
	
	ps_sort(&stack_a, &stack_b);
	
	ft_debug_print_stacks(&stack_a, &stack_b);
	
	ft_cleanup(sorted_array, &stack_a, &stack_b);
	return (0);	
}
