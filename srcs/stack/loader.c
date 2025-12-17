/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:28:20 by fomanca           #+#    #+#             */
/*   Updated: 2025/12/16 17:41:55 by fomanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	error_exit(t_node **a)
{
	free_all(a);
	write(2, "Error\n", 6);
	exit(1);
}

static int	check_dups(t_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->val == n)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	process_nodes(t_node **a, char **args)
{
	long	nb;
	int		j;

	j = 0;
	while (args[j])
	{
		nb = str_to_long(args[j]);
		if (nb > INT_MAX || nb < INT_MIN || check_dups(*a, (int)nb))
		{
			free_tab(args);
			error_exit(a);
		}
		add_back(a, (int)nb);
		j++;
	}
}

void	load_stack(t_node **a, char **av)
{
	int		i;
	char	**args;

	i = 0;
	while (av[i])
	{
		args = split_input(av[i], ' ');
		if (!args)
			error_exit(a);
		process_nodes(a, args);
		free_tab(args);
		i++;
	}
}
