/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:59:13 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/02/04 15:39:01 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	bubble_sort(int	*arr, int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	assign_index(t_list **stack_a, int *arr, int n)
{
	int		i;
	t_list	*current;

	current = *stack_a;
	while (current != NULL)
	{
		i = 0;
		while (i < n)
		{
			if (arr[i] == *(int *)current->content)
			{
				*(int *)current->content = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	assign_sorted_indices(t_list **stack_a, int *values, unsigned int size)
{
	int	*values_copy;

	values_copy = malloc(sizeof(int) * size);
	ft_memcpy(values_copy, values, size * sizeof(int));
	bubble_sort(values_copy, size);
	assign_index(stack_a, values_copy, size);
	free(values_copy);
}

void	bit_pass(t_list **a, t_list **b, unsigned int size, unsigned int bit)
{
	unsigned int	j;

	j = 0;
	while (j < size)
	{
		if (is_sorted(*a))
			break ;
		if (((*(int *)((*a)->content) >> bit) & 1) == 0)
			push_b(a, b);
		else
			rotate_a(a);
		j++;
	}
	while (*b != NULL)
		push_a(a, b);
}

void	radix_sort(t_list **stack_a, t_list **stack_b, int *values)
{
	unsigned int	size;
	unsigned int	max_value;
	unsigned int	max_bits;
	unsigned int	i;

	size = ft_lstsize(*stack_a);
	max_value = size - 1;
	max_bits = bit_length(max_value);
	assign_sorted_indices(stack_a, values, size);
	i = 0;
	while (i < max_bits)
	{
		bit_pass(stack_a, stack_b, size, i);
		i++;
	}
}
