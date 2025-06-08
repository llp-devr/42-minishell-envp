/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lepereir <lepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:50:36 by lepereir          #+#    #+#             */
/*   Updated: 2024/11/25 09:27:19 by lepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	if (*little == 0)
		return ((char *) big);
	little_len = ft_strlen(little);
	while (*big && little_len <= len)
	{
		if (*big == *little)
		{
			if (ft_strncmp(big, little, little_len) == 0)
				return ((char *) big);
		}
		big++;
		len--;
	}
	return (NULL);
}
