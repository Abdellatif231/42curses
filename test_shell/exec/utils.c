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

char	*std_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	l1;
	size_t	l2;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	ptr = malloc(l1 + l2 + 1);
	if (!ptr)
		return (NULL);
	while (i < l1)
		ptr[j++] = s1[i++];
	i = 0;
	while (i < l2)
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}
