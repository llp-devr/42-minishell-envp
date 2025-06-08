/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lepereir <lepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:32:04 by lepereir          #+#    #+#             */
/*   Updated: 2025/06/08 14:35:56 by lepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*__envp(const char *key, const char *value)
{
	char	*env1;
	char	*env2;

	env1 = ft_strjoin(key, "=");
	if (!env1)
		return (NULL);
	env2 = ft_strjoin(env1, value);
	free(env1);
	if (!env2)
		return (NULL);
	return (env2);
}

int	envp_set(t_minishell *ms, const char *key, const char *value)
{
	size_t	i;
	char	*envp;
	char	**tmp;

	if (!ms || !ms->envp || !key || !value)
		return (1);
	envp = __envp(key, value);
	if (!envp)
		return (1);
	envp_del(ms, key);
	tmp = ms->envp;
	ms->envp = envp_dup(tmp);
	if (!ms->envp)
	{
		ms->envp = tmp;
		free(envp);
		return (1);
	}
	free(tmp);
	i = 0;
	while (ms->envp[i])
		i++;
	ms->envp[i] = envp;
	return (0);
}
