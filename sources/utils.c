/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:31:32 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/02/11 18:43:05 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi_checked(const char *str, int *out)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && -(result) < INT_MIN))
			return (0);
		str++;
	}
	*out = (int)(result * sign);
	return (1);
}

char	**safe_split(char *arg)
{
	char	**split;

	split = ft_split(arg, ' ');
	if (!split || !split[0])
	{
		free_split(split);
		error_exit(NULL, NULL);
	}
	return (split);
}

int	append_split(char **tokens, char **split, int *k)
{
	int	j;

	j = 0;
	while (split[j])
	{
		tokens[*k] = ft_strdup(split[j]);
		if (!tokens[*k])
			return (free_split(tokens), free_split(split), 0);
		(*k)++;
		j++;
	}
	return (0);
}

int	count_tokens(int argc, char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**split;

	count = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j])
		{
			count++;
			j++;
		}
		free_split(split);
		i++;
	}
	return (count);
}
