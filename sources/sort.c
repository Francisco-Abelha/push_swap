/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:08:33 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/02/04 15:25:19 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	while (size > 3)
	{
		bring_min_to_top(stack_a);
		push_b(stack_a, stack_b);
		size--;
	}
	sort_3(stack_a);
	while (*stack_b)
		push_a(stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b, int *values)
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
	else if (count <= 5)
		sort_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b, values);
}
