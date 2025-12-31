/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 00:38:19 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/03 23:10:08 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*p;
	int		signal;
	int		ret;

	p = (char *)nptr;
	ret = 0;
	signal = 1;
	while (*p == ' '
		|| *p == '\f' || *p == '\n'
		|| *p == '\r' || *p == '\t' || *p == '\v')
		p++;
	if (*p == '+')
		p++;
	else if (*p == '-')
	{
		signal = -1;
		p++;
	}
	while (*p >= '0' && *p <= '9')
	{
		ret = ret * 10 + (*p - '0');
		p++;
	}
	return (ret * signal);
}
