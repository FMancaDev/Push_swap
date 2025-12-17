/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:51:06 by fomanca           #+#    #+#             */
/*   Updated: 2025/12/16 18:11:26 by fomanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	load_stack(&stack_a, av + 1);
	if (!check_sorted(stack_a))
	{
		if (get_size(stack_a) == 2)
			sa(&stack_a, 1);
		else if (get_size(stack_a) == 3)
			sort_tiny(&stack_a);
		else
			solve_complex(&stack_a, &stack_b);
	}
	free_all(&stack_a);
	return (0);
}
