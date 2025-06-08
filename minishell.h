/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lepereir <lepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:17:29 by lepereir          #+#    #+#             */
/*   Updated: 2025/06/08 14:30:30 by lepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>

# include "libft/libft.h"

// STRUCTS

typedef struct s_minishell
{
	char	**envp;
}	t_minishell;

// ENVP
int		__match_key(const char *envp, const char *key);

int		envp_del(t_minishell *ms, const char *key);
char	**envp_dup(char **envp);
char	*envp_get(t_minishell *ms, const char *key);
int		envp_set(t_minishell *ms, const char *key, const char *value);

// UTILS
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strncpy(char *dest, const char *src, size_t n);

#endif
