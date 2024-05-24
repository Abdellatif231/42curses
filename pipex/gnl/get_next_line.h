/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <amaaouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:20:58 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/11 10:52:27 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*gnl_strjoin(char *s1, char *s2);
int		gnl_strlen(char *s);
char	*gnl_strdup(char *s1);
int		newline_finder(char *string);
char	*buff_filter(char **str, int index);
void	rest_of_line(char **str, int index);
char	*ft_free(char **ptr);
char	*dubel_free(char **s1, char **s2);
#endif
