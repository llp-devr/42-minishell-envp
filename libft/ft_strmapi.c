/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lepereir <lepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:58:55 by lepereir          #+#    #+#             */
/*   Updated: 2024/11/25 09:27:01 by lepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	pos;

	ret = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (ret);
	pos = 0;
	while (s[pos] != '\0')
	{
		ret[pos] = (*f)(pos, s[pos]);
		pos++;
	}
	ret[pos] = '\0';
	return (ret);
}
