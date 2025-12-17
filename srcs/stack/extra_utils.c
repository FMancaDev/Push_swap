/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:18:30 by fomanca           #+#    #+#             */
/*   Updated: 2025/12/13 15:18:35 by fomanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*find_min(t_node *lst)
{
	long	min;
	t_node	*node;

	min = LONG_MAX;
	node = NULL;
	while (lst)
	{
		if (lst->val < min)
		{
			min = lst->val;
			node = lst;
		}
		lst = lst->next;
	}
	return (node);
}

t_node	*find_max(t_node *lst)
{
	long	max;
	t_node	*node;

	max = LONG_MIN;
	node = NULL;
	while (lst)
	{
		if (lst->val > max)
		{
			max = lst->val;
			node = lst;
		}
		lst = lst->next;
	}
	return (node);
}
