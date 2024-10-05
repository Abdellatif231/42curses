/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:50:47 by amaaouni          #+#    #+#             */
/*   Updated: 2024/10/04 17:02:12 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	delete_node(t_env *prev, t_env *curr, t_env **env)
{
	if (prev == NULL)
		*env = curr->next;
	else
		prev->next = curr->next;
	free(curr->env_line);
	free(curr);
	return ;
}

static void	remove_var(t_env **env, char *key)
{
	t_env	*curr;
	t_env	*prev;
	char	*eq_sign;
	int		key_len;

	curr = *env;
	prev = NULL;
	while (curr)
	{
		eq_sign = ft_strchr(curr->env_line, '=');
		if (eq_sign)
			key_len = eq_sign - curr->env_line;
		else
			key_len = ft_strlen(curr->env_line);
		if (ft_strncmp(curr->env_line, key, key_len) == 0
			&& key_len == ft_strlen(key))
			return (delete_node(prev, curr, env));
		prev = curr;
		curr = curr->next;
	}
}

void	ft_unset(char **args, t_env **env)
{
	if (!args[1])
	{
		printf("unset: not enough arguments\n");
		return ;
	}
	args++;
	while (*args)
	{
		remove_var(env, *args);
		args++;
	}
}
