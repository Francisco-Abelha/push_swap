/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 20:40:31 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/04 12:13:57 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_str(void *content)
{
	printf("  [%s]\n", (char *)content);
}

void	to_upper(void *content)
{
	char	*s;

	s = (char *)content;
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s -= 32;
		s++;
	}
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*next;

	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		next = lst->next;
		f(lst->content);
		lst = next;
	}
}
