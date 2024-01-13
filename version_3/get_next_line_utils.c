/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:11:07 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/01/11 07:26:07 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(char *s)
{
	ssize_t	len;

	len = 0;
	if (!s || *s == '\0')
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char **base, char *add)
{
	ssize_t	len;
	ssize_t	i;
	ssize_t	j;
	char	*join;

	i = 0;
	j = 0;
	if (*base == NULL)
		return (add);
	join = ft_duplicate(*base, 0, 0);
	*base = NULL;
	*base = malloc(sizeof(char) * (ft_strlen(join) + ft_strlen(add) + 1));
	if (!*base)
		return (NULL);
	while (i++ < ft_strlen(join) && join[i] != '\0')
		*base[i] = join[i];
	while (i++ < (ft_strlen(join) + ft_strlen(add)) && j++ < ft_strlen(add))
		*base[i] = add[j];
	*base[ft_strlen(join) + ft_strlen(add) + 1] = '\0';
	return (join = NULL, free(join), *base);
}

char	*ft_duplicate(char *str, ssize_t start, ssize_t end)
{
	char	*dup;
	ssize_t	len;
	ssize_t	count;

	if (!str)
		return (NULL);
	if (end == -1)
		end = ft_strlen(str);
	if (end >= start && start >= 0)
		len = (end - start) + 1;
	else
		return (NULL);
	count = 0;
	dup = NULL;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (count < len && str[start] != '\0')
	{
		dup[count] = str[start];
		start++;
		count++;
	}
	dup[count] = '\0';
	return (dup);
}

char	*ft_buf(int fd)
{
	ssize_t		bytes;
	static char	buf[BUFFER_SIZE + 1];
	char		*next;
	ssize_t		x;

	next = NULL;
	bytes = read(fd, buf, BUFFER_SIZE);
	buf[bytes + 1] = '\0';
	while (bytes > 0)
	{
		x = 0;
		while (x <= bytes && buf[x] != '\n')
			x++;
		if (!next)
			next = ft_duplicate(buf, 0, x);
		else if (next != NULL)
			next = ft_strjoin(*next, ft_duplicate(buf, 0, x));
	}
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		if ()
		bytes = read(fd, buf, BUFFER_SIZE);
		buf[bytes + 1] = '\0';
		x = 0;
		while (buf[x] != '\0' && buf[x] != '\n')
			x++;
		if (!next)
			next = ft_duplicate(buf, 0, x);
		else
			next = ft_strjoin(next, ft_duplicate(buf, 0, x));
		*buf = ft_save(buf, x + 1);
		return (next);
	}
	return (next);
}

char	*ft_save(char *buf, int x)
{
	int		y;
	char	new[BUFFER_SIZE + 1];

	y = 0;
	while (y <= x)
	{
		new[y] = buf[x + y];
		y++;
	}
	while (y <= BUFFER_SIZE + 1)
		new[y++] = '\0';
	return (*new);
}
