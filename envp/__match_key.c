/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __match_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lepereir <lepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 13:10:27 by lepereir          #+#    #+#             */
/*   Updated: 2025/06/08 14:18:52 by lepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	__match_key(const char *envp, const char *key)
{
	size_t	i;
	
	i = 0;
	while(key[i] && envp[i] && key[i] == envp[i])
		i++;
	return (key[i] == '\0' && envp[i] == '=');
}
