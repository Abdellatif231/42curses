/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelarra42 <bbelarra@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:17:33 by bbelarra42        #+#    #+#             */
/*   Updated: 2024/10/15 15:10:31 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// readline.h
//
// Copyright (c) 2014 Yorkie Neil <yorkiefixer@gmail.com>
//

#ifndef READLINE__H_
# define READLINE__H_

/*
 * Readline struct
 */

typedef struct readline_s
{
	char	*buffer;
	size_t	cursor;
	size_t	line;
}			readline_t;

/*
 * create a new readline struct
 */
readline_t	*readline_new(char *buffer);

/*
 * next cursor
 */
char		*readline_next(readline_t *rl);

/*
 * Get last line of a buffer, ignoring any context of readline
 */
char		*readline_last_from_rl(readline_t *rl);

/*
 * Get the last line directly buffer
 */
char		*readline_last(char *buffer);

/*
 * free the object
 */
void		readline_free(readline_t *rl);
void		rl_replace_line (const char *string, int clear_undo);
#endif
