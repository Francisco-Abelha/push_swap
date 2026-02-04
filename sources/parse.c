/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:33:39 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/02/03 17:35:17 by fgoncal2         ###   ########.fr       */
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
		error_exit(NULL, NULL);
	i = 1;
	k = 0;
	while (i < argc)
	{
		split = safe_split(argv[i]);
		append_split(tokens, split, &k);
		free_split(split);
		i++;
	}
	tokens[k] = NULL;
	return (tokens);
}

static void	validate_token(const char *token)
{
	int	i;

	i = 0;
	if (token[i] == '+' || token[i] == '-')
		i++;
	if (!token[i])
		error_exit(NULL, NULL);
	while (token[i])
	{
		if (!ft_isdigit(token[i]))
			error_exit(NULL, NULL);
		i++;
	}
}

static void	check_duplicates(int *values, int count)
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
				error_exit(NULL, NULL);
			j++;
		}
		i++;
	}
}

static void	build_stack(t_list **stack_a, int *values, int count)
{
	t_list	*node;
	int		i;

	i = 0;
	while (i < count)
	{
		node = ft_lstnew(&values[i]);
		if (!node)
			error_exit(stack_a, NULL);
		ft_lstadd_back(stack_a, node);
		i++;
	}
}

int	*parse_arguments(int argc, char **argv, t_list **stack_a)
{
	char	**tokens;
	int		*values;
	int		count;
	int		i;

	tokens = collect_tokens(argc, argv);
	count = count_tokens(argc, argv);
	values = malloc(sizeof(int) * count);
	if (!values)
		error_exit(stack_a, NULL);
	i = 0;
	while (i < count)
	{
		validate_token(tokens[i]);
		values[i] = ft_atoi_checked(tokens[i]);
		i++;
	}
	check_duplicates(values, count);
	build_stack(stack_a, values, count);
	free_split(tokens);
	return (values);
}
