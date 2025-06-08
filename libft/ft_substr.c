/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lepereir <lepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:35:34 by lepereir          #+#    #+#             */
/*   Updated: 2024/11/25 09:27:56 by lepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_min(size_t v1, size_t v2)
{
	if (v1 < v2)
		return (v1);
	return (v2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	dst_size;

	if (start > ft_strlen(s))
		dst_size = 1;
	else
		dst_size = (ft_min(ft_strlen(&s[start]), len) + 1);
	dst = (char *) malloc(sizeof(char) * dst_size);
	if (!dst)
		return (dst);
	if (dst_size == 1)
		*dst = '\0';
	else
		ft_strlcpy(dst, &s[start], dst_size);
	return (dst);
}
