/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lepereir <lepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:30:00 by lepereir          #+#    #+#             */
/*   Updated: 2024/11/25 09:26:13 by lepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = (char *) malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dst)
		return (dst);
	ft_strlcpy(dst, s1, (s1_len + 1));
	ft_strlcat(dst, s2, (s1_len + s2_len + 1));
	return (dst);
}
