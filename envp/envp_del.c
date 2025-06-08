/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lepereir <lepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:03:02 by lepereir          #+#    #+#             */
/*   Updated: 2025/06/08 14:17:32 by lepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	__envp_rotate(t_minishell *ms)
{
	char	*temp;
	size_t	i;
	size_t	size;

	size = 0;
	while (ms->envp[size])
		size++;
	if (size > 1)
	{
		temp = ms->envp[0];
		i = 0;
		while (i < (size - 1))
		{
			ms->envp[i] = ms->envp[i + 1];
			i++;
		}
		ms->envp[i] = temp;
	}
}


int	envp_del(t_minishell *ms, const char *key)
{
	size_t	envp_len;

	if(envp_get(ms, key) == NULL)
		return (1);
	envp_len = 0;
	while (ms->envp[envp_len])
		envp_len++;
	while (!__match_key(ms->envp[envp_len - 1], key))
		__envp_rotate(ms);
	free(ms->envp[envp_len - 1]);
	ms->envp[envp_len - 1] = NULL;
	return (0);
}
