/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:24:17 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/01/06 09:27:59 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next(char *buf, char *next)
{
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (!next || next == NULL)
		next = ft_duplicate(buf, 0, i);
	else
	{
		temp = ft_duplicate(next, 0, -1);
		next = NULL;
		next = ft_strjoin(temp, ft_duplicate(buf, 0, i));
		temp = NULL;
	}
	return (next);
}

char	*ft_rest(char *buf)
{
	char	*rest;
	int		x;

	rest = NULL;
	x = 0;
	while (buf[x] != '\0' && buf[x] != '\n')
		x++;
	if (buf[x] == '\n' && buf[x + 1] != '\0')
		rest = ft_duplicate(buf, x + 1, -1);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buf;
	char		*next;

	if (fd < 0 || BUFSIZE <= 0)
		return (NULL);
	next = NULL;
	if (!rest)
		rest = NULL;
	buf = ft_read_fd(fd, rest);
	while (buf != NULL && next[ft_strlen(next) - 1] != '\n')
	{
		rest = NULL;
		rest = ft_next(buf, next);
		next = NULL;
		next = ft_duplicate(rest, 0, -1);
		rest = NULL;
		if (next[ft_strlen(next) - 1] == '\n')
		{
			if (ft_rest(buf) != NULL)
				rest = ft_rest(buf);
			return (buf = NULL, next);
		}
		buf = ft_read_fd(fd, rest);
	}
	if (next == NULL && rest == NULL)
		return (free(rest), free(next), free(buf), NULL);
	return (buf = NULL, next);
}
