#include "exec.h"

static void remove_var(t_env **env, char *key)
{
    t_env *curr;
    t_env *prev;
    char *eq_sign;
    int key_len;

    curr = *env;
    prev = NULL;
    while (curr)
    {
        eq_sign = ft_strchr(curr->env_line, '=');
        if (eq_sign)
            key_len = eq_sign - curr->env_line;
        else
            key_len = ft_strlen(curr->env_line);

        if (strncmp(curr->env_line, key, key_len) == 0 && key_len == (int)strlen(key))
        {
            if (prev == NULL)
                *env = curr->next;
            else
                prev->next = curr->next;

            free(curr->env_line);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void ft_unset(char **args, t_env **env)
{
    if (!args[1])
    {
        printf("unset: not enough arguments\n");
        return;
    }

    args++;
    while (*args)
    {
        remove_var(env, *args);
        args++;
    }
}