/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 14:25:32 by fomanca           #+#    #+#             */
/*   Updated: 2025/12/13 15:17:53 by fomanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_size(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_node	*get_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back(t_node **lst, int n)
{
	t_node	*new_node;
	t_node	*last;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->val = n;
	new_node->next = NULL;
	if (!*lst)
	{
		*lst = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last = get_last(*lst);
		last->next = new_node;
		new_node->prev = last;
	}
}

void	free_all(t_node **lst)
{
	t_node	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

int	check_sorted(t_node *lst)
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (lst->val > lst->next->val)
			return (0);
		lst = lst->next;
	}
	return (1);
}
