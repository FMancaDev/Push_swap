/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:19:03 by fomanca           #+#    #+#             */
/*   Updated: 2025/12/13 18:04:01 by fomanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../srcs/gnl/get_next_line.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static void	parse_command(t_node **a, t_node **b, char *command)
{
	if (!ft_strcmp(command, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(command, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(command, "pb\n"))
		pb(b, a, 0);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b, 0);
	else
		error_exit(a);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	load_stack(&a, av + 1);
	line = get_next_line(0);
	while (line)
	{
		parse_command(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (check_sorted(a) && get_size(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(&a);
	free_all(&b);
	return (0);
}
