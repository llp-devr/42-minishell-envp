/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lepereir <lepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:39:00 by lepereir          #+#    #+#             */
/*   Updated: 2024/11/25 09:22:30 by lepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s1;

	s1 = (unsigned char *) b;
	if (len != 0 || b != NULL)
	{
		while (len > 0)
		{
			*s1 = (unsigned char) c;
			s1++;
			len--;
		}
	}
	return (b);
}
