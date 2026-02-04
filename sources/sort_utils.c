/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:37:55 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/02/04 15:37:30 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_list *a)
{
	int	min;
	int	val;

	min = *(int *)a->content;
	while (a)
	{
		val = *(int *)a->content;
		if (val < min)
			min = val;
		a = a->next;
	}
	return (min);
}

int	find_index(t_list *a, int target)
{
	int	i;

	i = 0;
	while (a)
	{
		if (*(int *)a->content == target)
			return (i);
		i++;
		a = a->next;
	}
	return (-1);
}

void	bring_min_to_top(t_list **stack_a)
{
	int	min;
	int	index;
	int	size;

	min = find_min(*stack_a);
	index = find_index(*stack_a, min);
	size = ft_lstsize(*stack_a);
	if (index <= size / 2)
	{
		while (index-- > 0)
			rotate_a(stack_a);
	}
	else
	{
		while (index++ < size)
			reverse_rotate_a(stack_a);
	}
}

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

int	bit_length(unsigned int value)
{
	unsigned int	max_bits;

	max_bits = 0;
	while (value > 0)
	{
		max_bits++;
		value >>= 1;
	}
	return (max_bits);
}
