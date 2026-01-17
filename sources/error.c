/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:07:46 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/01/16 23:41:45 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

long ft_atoi_safe(const char *str)
{
	long result;
	int sign;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}

	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}

	return result * sign;
}

int	parse_int(const char *str)
{
	long	num;
	int		i;

	if ((!*str || (*str == '+' || *str == '-')) && (!str[1]))
		print_error_and_exit();
	num = ft_atoi_safe(str);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			print_error_and_exit();
		i++;
	}
	if (num < INT_MIN || num > INT_MAX)
		print_error_and_exit();
	return ((int)num);
}

void	check_duplicates(int *arr, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[i] == arr[j])
				print_error_and_exit();
			j++;
		}
		i++;
	}
}

int	*parse_args(int argc, char **argv)
{
	int	*numbers;
	int	i;

	if (argc < 2)
		return (NULL);
	numbers = malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < argc - 1)
	{
		numbers[i] = parse_int(argv[i + 1]);
		i++;
	}
	check_duplicates(numbers, argc - 1);
	return (numbers);
}
