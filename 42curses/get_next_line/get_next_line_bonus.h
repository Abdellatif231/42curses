/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <amaaouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:20:58 by amaaouni          #+#    #+#             */
/*   Updated: 2024/02/08 16:08:41 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
char	*ft_strdup(char *s1);
int		newline_finder(char *string);
char	*buff_filter(char **str, int index);
void	rest_of_line(char **str, int index);
char	*ft_free(char **ptr);
char	*dubel_free(char **s1, char **s2);
#endif
