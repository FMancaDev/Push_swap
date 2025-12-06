/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:51:06 by fomanca           #+#    #+#             */
/*   Updated: 2025/12/06 16:23:35 by fomanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*temp;

	a = NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);

	init_stack_a(&a, argv + 1);

	printf("\n--- O MEU STACK A ---\n");
	temp = a;
	while (temp)
	{
		printf("Node: %d\n", temp->value);
		temp = temp->next;
	}
	printf("---------------------\n");

	free_stack(&a); 
	return (0);
}
