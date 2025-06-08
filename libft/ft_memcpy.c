/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lepereir <lepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:26:04 by lepereir          #+#    #+#             */
/*   Updated: 2024/11/25 09:22:03 by lepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (len == 0 || dst == src)
		return (dst);
	s1 = (unsigned char *) dst;
	s2 = (unsigned char *) src;
	while (len > 0)
	{
		*s1 = *s2;
		s1++;
		s2++;
		len--;
	}
	return (dst);
}
