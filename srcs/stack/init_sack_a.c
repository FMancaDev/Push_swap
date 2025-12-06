/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:19:51 by fomanca           #+#    #+#             */
/*   Updated: 2025/12/06 17:29:50 by fomanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	error_syntax(char *str_n) // verifica se e apenas um numero, sinal
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	if (*str_n == '+' || *str_n == '-')
		str_n++;
	while (*str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
		str_n++;
	}
	return (0);
}

static int	error_duplicate(t_stack *a, int n)  // verifica duplicados
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	init_stack_a(t_stack **a, char **argv) // parser principal
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n); // se tudo correr bem adicionamos a stack
		i++;
	}
}
