/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:08:33 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/01/15 20:35:18 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_list *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (*(int *)stack_a->content > *(int *)stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	sort_3(t_list **stack_a)
{
	int	x;
	int	y;
	int	z;

	x = *(int *)(*stack_a)->content;
	y = *(int *)(*stack_a)->next->content;
	z = *(int *)(*stack_a)->next->next->content;

	if ((x > y && y < z) && (x < z))
		swap_a(stack_a);
	else if (x > y && y > z)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if ((x > y && y < z) && (x > z))
		rotate_a(stack_a);
	else if ((x < y && y > z) && (x < z))
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if ((x < y && y > z) && (x > z))
		reverse_rotate_a(stack_a);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	//placeholders
	swap_a(stack_a);
	swap_b(stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	count;

	count = ft_lstsize(*stack_a);
	if (count <= 1)
		return ;
	else if (count == 2)
	{
		if (!is_sorted(*stack_a))
			swap_a(stack_a);
	}
	else if (count == 3)
		sort_3(stack_a);
	/* else if (count <= 5)
		sort_5(stack_a, stack_b); */
	else
		radix_sort(stack_a, stack_b);
}
