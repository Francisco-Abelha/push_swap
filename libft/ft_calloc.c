/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 01:00:41 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/04 11:46:25 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb * size > __SIZE_MAX__)
		return (malloc(1));
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	ft_memset(array, 0, size * nmemb);
	return (array);
}
