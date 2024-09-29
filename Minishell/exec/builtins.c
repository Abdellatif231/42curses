#include "exec.h"

void    ft_echo(char **arg)
{
    int new_line;

    new_line = 0;
    if (arg[1] && !strcmp(arg[1], "-n"))
        new_line = 1;
    arg++;
    while (*arg)
    {
        printf("%s", *arg);
        if (*(arg + 1))
            printf(" ");
        arg++;
    }
    if (!new_line)
        printf("\n");
}

int     ft_cd(char **arg)
{
    char    *path;
    // this not gonna work now becuz of how command arg works
    if (arg[2])
        printf("cd : too many arguments\n%s\n", arg[2]);
    else if (!arg[1] || !arg[1][0])
    {
        path = getenv("HOME");
        printf("path %s\n", path);
    }
    else if (!strcmp(arg[1], "-"))
    // implement you own getenv btw
        path = getenv("OLDPWD");
    else
         path = arg[1];
    // update the env 
    return chdir(path);
}

void    ft_pwd(void)
{
    char *pwd;

    pwd = getcwd(NULL, 0);
    if (pwd)
    {
        printf("%s\n", pwd);
        free(pwd);
    }
    else
        perror("getcwd");
}



int main(int ac, char **arg)
{
    int i = 0;
    ft_pwd();
    
    printf("%d\n", i);
}