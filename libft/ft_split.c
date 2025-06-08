/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lepereir <lepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:59:11 by lepereir          #+#    #+#             */
/*   Updated: 2024/11/25 09:25:31 by lepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_substring_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static size_t	ft_substring_len(const char *s, char c)
{
	size_t	len;

	if (ft_strchr(s, c) == NULL)
		len = ft_strlen(s);
	else
		len = ft_strchr(s, c) - s;
	return (len);
}

static void	ft_free_array(char **arr)
{
	char	**cache;

	cache = arr;
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(cache);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	pos;

	ret = (char **) malloc(sizeof(char *) * (ft_substring_count(s, c) + 1));
	if (!ret)
		return (NULL);
	pos = 0;
	while (*s && s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			ret[pos] = ft_substr(s, 0, ft_substring_len(s, c));
			if (!ret[pos])
			{
				ft_free_array(ret);
				return (NULL);
			}
			pos++;
			s += ft_substring_len(s, c);
		}
	}
	ret[pos] = NULL;
	return (ret);
}
