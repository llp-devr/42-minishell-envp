/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lepereir <lepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 00:21:40 by lepereir          #+#    #+#             */
/*   Updated: 2024/11/25 09:21:31 by lepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	*s;

	if (len == 0)
		return (NULL);
	s = (unsigned char *) b;
	while (*s != (unsigned char) c && len > 1)
	{
		s++;
		len--;
	}
	if (*s == (unsigned char) c)
		return ((void *) s);
	return (NULL);
}
