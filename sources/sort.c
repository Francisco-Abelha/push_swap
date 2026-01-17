/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:08:33 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/01/17 02:28:59 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_min(t_list *a)
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

static int	find_index(t_list *a, int target)
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

static void	bring_min_to_top(t_list **stack_a)
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

void	sort(t_list **stack_a, t_list **stack_b, int *numbers)
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
		radix_sort(stack_a, stack_b, numbers);
}
