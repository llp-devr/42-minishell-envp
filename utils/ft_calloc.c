/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lepereir <lepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:53:17 by lepereir          #+#    #+#             */
/*   Updated: 2025/06/08 12:22:38 by lepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	total_size;

	total_size = nmemb * size;
	if (total_size == 0 || (total_size / nmemb) != size)
		return (NULL);
	alloc = malloc(total_size);
	if (!alloc)
		return (NULL);
	ft_memset(alloc, 0, nmemb * size);
	return (alloc);
}
