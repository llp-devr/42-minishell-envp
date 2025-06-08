/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lepereir <lepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:32:04 by lepereir          #+#    #+#             */
/*   Updated: 2025/06/08 13:16:42 by lepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*envp_get(t_minishell *ms, const char *key)
{
	size_t	i;

	if (!ms || !ms->envp || !key)
		return (NULL);
	i = 0;
	while(ms->envp[i])
	{
		if (__match_key(ms->envp[i], key))
			return (&ms->envp[i][ft_strlen(key) + 1]);
		i++;
	}
	return (NULL);
}
