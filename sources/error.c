/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:07:46 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/01/23 20:42:09 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Helper function to free a split array
static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// Helper function for parsing single arg (argc == 2)
static int	*parse_single_arg(char *arg, int *count_out)
{
	char	**split;
	int		*numbers;
	int		i;
	int		error;

	split = ft_split(arg, ' ');
	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
		i++;
	*count_out = i;
	if (*count_out == 0)
	{
		free_split(split);
		return (NULL);
	}
	numbers = malloc(sizeof(int) * (*count_out));
	if (!numbers)
	{
		free_split(split);
		return (NULL);
	}
	i = 0;
	while (i < *count_out)
	{
		numbers[i] = parse_int(split[i], &error);
		if (error)
		{
			free(numbers);
			free_split(split);
			return(NULL);
		}
		i++;
	}
	free_split(split);
	return (numbers);
}

long	ft_atoi_safe(const char *str)
{
	long	result;
	int		sign;

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
	return (result * sign);
}

int	parse_int(const char *str, int *error)
{
	long	num;
	int		i;

	*error = 0;
	if ((!*str || (*str == '+' || *str == '-')) && (!str[1]))
	{
		*error = 1;
		return (0);
	}
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			*error = 1;
			return (0);
		}
		i++;
	}
	num = ft_atoi_safe(str);
	if (num < INT_MIN || num > INT_MAX)
	{
		*error = 1;
		return (0);
	}
	return ((int)num);
}

int	check_duplicates(int *arr, int count)
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*parse_args(int argc, char **argv, int *count_out)
{
	int	*numbers;
	int	i;
	int	error;

	*count_out = 0;

	if (argc < 2)
		return (NULL);
	if (argc == 2)
	{
		// Check if arg is empty or only whitespace BEFORE calling parse_single_arg
		if (!argv[1] || !argv[1][0])
			return (NULL);  // Empty string - not an error
		// Check if only whitespace
		i = 0;
		while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i++;
		if (!argv[1][i])
			return (NULL);  // Only whitespace - not an error
		numbers = parse_single_arg(argv[1], count_out);
		if (!numbers)
		{
			if (*count_out == 0)
				return (NULL);
			*count_out = -1;
			return (NULL);
		}
		if (check_duplicates(numbers, *count_out))
		{
			free(numbers);
			*count_out = -1;
			return (NULL);
		}
		// If parse_single_arg returns NULL here, it's a real error
		// (invalid numbers, duplicates, etc.)
		return (numbers);
	}
	else
	{
		*count_out = argc -1;
		numbers = malloc(sizeof(int) * (*count_out));
		if (!numbers)
		{
			*count_out = -1;
			return (NULL);
		}
		i = 0;
		while (i < *count_out)
		{
			numbers[i] = parse_int(argv[i + 1], &error);
			if (error)
			{
				free(numbers);
				*count_out = -1;
				return (NULL);
			}
			i++;
		}
	}
	if (check_duplicates(numbers, *count_out))
	{
		free(numbers);
		*count_out = -1;
		return (NULL);
	}
	return (numbers);
}
