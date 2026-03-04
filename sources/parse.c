/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:33:39 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/02/11 18:42:00 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	**collect_tokens(int argc, char **argv)
{
	char	**tokens;
	char	**split;
	int		count;
	int		i;
	int		k;

	count = count_tokens(argc, argv);
	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
		return (NULL);
	i = 1;
	k = 0;
	while (i < argc)
	{
		split = safe_split(argv[i]);
		if (!split)
		{
			tokens[k] = NULL;
			return (free_split(tokens), NULL);
		}
		if (!append_split(tokens, split, &k))
			return (free_split(split), free_split(tokens), NULL);
		free_split(split);
		i++;
	}
	tokens[k] = NULL;
	return (tokens);
}

static int	validate_token(const char *token)
{
	int	i;

	i = 0;
	if (token[i] == '+' || token[i] == '-')
		i++;
	if (!token[i])
		return (0);
	while (token[i])
	{
		if (!ft_isdigit(token[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_duplicates(int *values, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (values[i] == values[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	build_stack(t_list **stack_a, int *values, int count)
{
	t_list	*node;
	int		i;

	i = 0;
	while (i < count)
	{
		node = ft_lstnew(&values[i]);
		if (!node)
		{
			free_stack(stack_a);
			return (0);
		}
		ft_lstadd_back(stack_a, node);
		i++;
	}
	return (1);
}

int	*parse_arguments(int argc, char **argv, t_list **stack_a)
{
	char	**tokens;
	int		*values;
	int		count;
	int		i;

	tokens = collect_tokens(argc, argv);
	if (!tokens)
		return (NULL);
	count = 0;
	while (tokens[count])
		count++;
	if (count == 0)
		return (free_split(tokens), NULL);
	values = malloc(sizeof(int) * count);
	if (!values)
		return (free_split(tokens), NULL);
	i = 0;
	while (i < count)
	{
		if (!validate_token(tokens[i]))
			return (free(values), free_split(tokens), NULL);
		if (!ft_atoi_checked(tokens[i], &values[i]))
			return (free(values), free_split(tokens), NULL);
		i++;
	}
	if (!check_duplicates(values, count))
		return (free(values), free_split(tokens), NULL);
	if (!build_stack(stack_a, values, count))
		return (free(values), free_split(tokens), NULL);
	free_split(tokens);
	return (values);
}
