/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:59:13 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/01/21 19:03:22 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	bit_length(unsigned int value)
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

void	radix_sort(t_list **stack_a, t_list **stack_b, int *numbers)
{
	unsigned int	size;
	unsigned int	max_value;
	unsigned int	max_bits;
	unsigned int	i;
	unsigned int	j;
	int				*numbers_copy;

	i = 0;
	size = ft_lstsize(*stack_a);
	max_value = size - 1;
	max_bits = bit_length(max_value);
	numbers_copy = malloc(sizeof(int) * size);
	ft_memcpy(numbers_copy, numbers, size * sizeof(int));
	bubble_sort(numbers_copy, size);
	assign_index(stack_a, numbers_copy, size);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (is_sorted(*stack_a))
				break ;
			if (((*(int *)((*stack_a)->content) >> i) & 1) == 0)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
			j++;
		}
		while (*stack_b != NULL)
			push_a(stack_a, stack_b);
		i++;
	}
}
