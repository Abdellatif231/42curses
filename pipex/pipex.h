/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:21:38 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/18 16:35:38 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct t_var
{
	int		i;
	int		prv_fd;
	int		infd;
	int		outfd;
	int		flag;
	int		fd[2];
	pid_t	pid;
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd;
	char	*pathname;
}			t_va;

typedef struct t_split
{
	char	**final;
	char	**arr;
	char	**tmp;
	int		i;
	int		count;
}			t_par;

typedef struct t_check_path
{
	char	*path;
	char	*pathname;
	char	**env_paths;
	char	**env_to_free;
}			t_path;

char		**split_command(char const *s, char c);
int			open_files(t_va *va_l, char *av[], int ac);
void		redirect_io(t_va *va_l, int ac);
int			execute_cmd(t_va *va_l, int ac, char *av[], char *ev[]);
char		*find_path(char *ev[]);
char		*check_path(char *cmd, char *ev[]);
void		here_doc(t_va *va_l, char *limiter);
char		**final_split(char *str, char c);
int			ft_close(t_va *va);
int			free_split(char **arr);
void		pipe_error(void);

#endif
