/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:58:47 by amaaouni          #+#    #+#             */
/*   Updated: 2024/10/03 22:43:52 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int ft_isalpha(int c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return (1);
    return (0);
}

void	print_var(t_env *env)
{
	while (env)
	{
		printf("declare -x %s\n", env->env_line);
		env = env->next;
	}
}

void	remove_var(t_env **head, t_env *target)
{
    t_env *current;
    t_env *prev;

	current = *head;
	prev = NULL;
    if (current == target) {
        *head = current->next;
        free(target->env_line);
        free(target);
        return;
    }

    while (current && current != target) {
        prev = current;
        current = current->next;
    }

    if (current == target) {
        prev->next = current->next;
        free(target->env_line);
        free(target);
    }
}

int	search(t_env **env, char *key, char *val)
{
	t_env	*curr;
	char	*env_key;
	char	*eq;
	int		key_len;

	curr = *env;
	while (curr)
	{
		eq = ft_strchr(curr->env_line, '=');
		if (eq)
			key_len = eq - curr->env_line;
		else
			key_len = ft_strlen(curr->env_line);
		env_key = curr->env_line;
		if (ft_strlen(key) == key_len && !ft_strncmp(env_key, key, key_len))
		{
			if (!val)
				return 0;
			remove_var(env, curr);
			return 1;
		}
		curr = curr->next;
	}
	return 1;
}

int	rm_exists(t_env **env, char *var)
{
	char	*key;
	char	*eq_sign;
	int		res;

	eq_sign = ft_strchr(var, '=');
	if (eq_sign)
		*eq_sign = '\0';
	key = var;
	res = search(env, key, eq_sign);
	if (eq_sign)
		*eq_sign = '=';
	return res;

}

void	ft_export(char **arg, t_env **env)
{
	if (!arg[1])
		print_var(*env);
	else
	{
		arg++;
		while (*arg)
		{
			if (ft_isalpha(**arg) || **arg == '_')
			{
				if (rm_exists(env, *arg))
					env_add_back(env, env_new(ft_strdup(*arg)));
			}
			else
			{
				ft_putstr_fd("export: ", 2);
				ft_putstr_fd(*arg, 2);
				ft_putstr_fd(": not a valid identifier\n", 2);
			}
			arg++;
		}
	}
}
