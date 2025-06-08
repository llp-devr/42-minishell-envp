/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lepereir <lepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:35:26 by lepereir          #+#    #+#             */
/*   Updated: 2024/11/25 09:21:19 by lepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	num_of_digits(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*ret;
	size_t			pos;
	unsigned int	nbr;

	pos = num_of_digits(n);
	ret = (char *) malloc(sizeof(char) * (pos + 1));
	if (!ret)
		return (ret);
	ret[pos] = '\0';
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
	{
		ret[0] = '-';
		nbr = (unsigned int) -n;
	}
	else
		nbr = (unsigned int) n;
	while (nbr > 0)
	{
		pos--;
		ret[pos] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (ret);
}
