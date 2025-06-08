/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lepereir <lepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:50:47 by lepereir          #+#    #+#             */
/*   Updated: 2024/11/25 09:22:13 by lepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (dst == src)
		return (dst);
	s1 = (unsigned char *) dst;
	s2 = (unsigned char *) src;
	if (s2 < s1)
	{
		s1 += len;
		s2 += len;
		while (len-- > 0)
			*--s1 = *--s2;
	}
	else
	{
		while (len-- > 0)
			*s1++ = *s2++;
	}
	return (dst);
}
