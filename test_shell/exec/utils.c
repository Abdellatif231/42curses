/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 07:09:26 by amaaouni          #+#    #+#             */
/*   Updated: 2024/10/02 07:52:50 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char **env_to_arr(t_env *env)
{
	char	**arr;
	int		size;
	int		i;

    size = env_size(env);
    arr = malloc((size + 1) * sizeof(char *));
    if (!arr)
        return NULL;
    i = 0;
	if (!env)
		printf("fuck you\n");
    while (env)
    {
        arr[i] = env->env_line;
        i++;
        env = env->next;
    }
    arr[i] = NULL;
    return arr;
}
