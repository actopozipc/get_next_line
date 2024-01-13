/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:24:17 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/01/12 17:14:16 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buf(int fd)
{
	ssize_t	bytes;
	char	*buf;

	buf = NULL;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes <= 0)
		return (NULL);
	buf[bytes + 1] = '\0';
	return (buf);
}

char	*ft_next(char *buf, int fd)
{
	char	*temp;
	char	*next;

	next = NULL;
	while (ft_strchr(buf, '\n') == -1)
	{
		temp = NULL;
		temp = ft_strjoin(next, ft_duplicate(buf, 0, -1));
		next = NULL;
		next = ft_duplicate(temp, 0, -1);
		temp = NULL;
		buf = NULL;
		buf = ft_buf(fd);
	}
	if (ft_strchr(buf, '\n') >= 0)
	{
		temp = ft_strjoin (next, ft_duplicate(buf, 0, -1));
		next = NULL;
		next = ft_duplicate(temp, 0, -1);
		temp = NULL;
	}
	if (ft_strchr(buf, '\n') == -2 && next == NULL)
		return (buf = NULL, free(buf), free(next), NULL);
	return (buf = NULL, next);
}

char	*get_next_line(int fd)
{
	static char	*buf;	
	char		*next;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next = NULL;
	while (ft_buf(fd) != NULL || buf != NULL)
	{
		if (!buf)
			buf = ft_buf(fd);
		temp = NULL;
		temp = ft_next(buf, fd);
		if (temp == NULL)
			return (NULL);
		next = ft_duplicate(temp, 0, ft_strchr(temp, '\n'));
		if (next && ft_strchr(temp, '\n') >= 0)
		{
			buf = ft_duplicate(temp, ft_strchr(temp, '\n') + 1, -1);
			return (temp = NULL, next);
		}
	}
	if (!next)
		return (temp = NULL, free(temp), free(next), free(buf), NULL);
	return (next);
}
