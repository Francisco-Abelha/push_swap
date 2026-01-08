/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:32:48 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/01/08 14:59:54 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*old_head;
	t_list	*last;
	t_list	*second_last;
	t_list	*traversal;
	
	if (ft_lstsize(*stack) > 1)
	{
		last = ft_lstlast(*stack);
		old_head = (*stack);
		traversal = (*stack);
		while (traversal->next != NULL)
		{
			if (traversal->next->next == NULL)
				second_last = traversal;
			traversal = traversal->next;
		}
		second_last->next = NULL;
		last->next = old_head;
		*stack = last;
	}
}

void	reverse_rotate_a(t_list **stack_a)
{
	reverse_rotate(stack_a);
}

void	reverse_rotate_b(t_list **stack_b)
{
	reverse_rotate(stack_b);
}

void	reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}