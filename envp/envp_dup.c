/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lepereir <lepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:37:16 by lepereir          #+#    #+#             */
/*   Updated: 2025/06/08 14:29:11 by lepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**envp_dup(char **envp)
{
	char	**copy;
	size_t	i;
	size_t	j;

	i = 0;
	while (envp[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 2));
	if (!copy)
		return (NULL);
	j = 0;
	while (j < i)
	{
		copy[j] = ft_strdup(envp[j]);
		j++;
	}
	copy[j] = NULL;
	copy[j + 1] = NULL;
	return (copy);
}
