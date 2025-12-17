/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:33:45 by fomanca           #+#    #+#             */
/*   Updated: 2025/12/13 15:22:42 by fomanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;
}

void	sa(t_node **a, int p)
{
	swap(a);
	if (p)
		write(1, "sa\n", 3);
}

void	sb(t_node **b, int p)
{
	swap(b);
	if (p)
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, int p)
{
	swap(a);
	swap(b);
	if (p)
		write(1, "ss\n", 3);
}
