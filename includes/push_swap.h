/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:30:16 by fomanca           #+#    #+#             */
/*   Updated: 2025/12/13 18:00:55 by fomanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# include "../srcs/gnl/get_next_line.h"

typedef struct s_node
{
	int				val;
	int				pos;
	int				price;
	int				above_med;
	int				best_match;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// Parsing & Stack (srcs/stack)
void	load_stack(t_node **a, char **av);
void	free_all(t_node **lst);
void	add_back(t_node **lst, int n);
t_node	*get_last(t_node *lst);
t_node	*find_min(t_node *lst);
t_node	*find_max(t_node *lst);
int		get_size(t_node *lst);
int		check_sorted(t_node *lst);

// Utils (srcs/utils)
long	str_to_long(const char *s);
char	**split_input(char *s, char c);
void	free_tab(char **tab);
void	error_exit(t_node **a);

// Operations (srcs/operations)
void	sa(t_node **a, int p);
void	sb(t_node **b, int p);
void	ss(t_node **a, t_node **b, int p);
void	pa(t_node **a, t_node **b, int p);
void	pb(t_node **b, t_node **a, int p);
void	ra(t_node **a, int p);
void	rb(t_node **b, int p);
void	rr(t_node **a, t_node **b, int p);
void	rra(t_node **a, int p);
void	rrb(t_node **b, int p);
void	rrr(t_node **a, t_node **b, int p);

// Sorting (srcs/sort)
void	sort_tiny(t_node **a);
void	solve_complex(t_node **a, t_node **b);
void	update_nodes(t_node *a, t_node *b);

#endif
