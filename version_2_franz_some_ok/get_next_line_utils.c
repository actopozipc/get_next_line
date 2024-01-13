/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:11:07 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/01/11 02:36:48 by lbaumeis         ###   ########.fr       */
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

char	*ft_strjoin(char *base, char *add)
{
	ssize_t	len;
	ssize_t	i;
	ssize_t	j;
	char	*join;

	i = 0;
	j = 0;
	if (add == NULL)
		return (base);
	if (base == NULL)
		return (add);
	len = ft_strlen(base) + ft_strlen(add) - 1;
	join = malloc(sizeof(char) * len);
	if (!join || len <= 0)
		return (NULL);
	while (base[i] != '\0')
	{
		join[i] = base[i];
		i++;
	}
	while (add[j] != '\0')
		join[i++] = add[j++];
	join[i] = '\0';
	return (join);
}

char	*ft_duplicate(char *str, ssize_t start, ssize_t end)
{
	char	*dup;
	ssize_t	len;
	ssize_t	count;

	if (!str)
		return (NULL);
	if (end == 0)
		end = ft_strlen(str);
	if (end > start && start >= 0)
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
	while (bytes > 0)
	{
		buf[bytes + 1] = '\0';
		x = 0;
		while (buf[x] != '\0' && buf[x] != '\n')
			x++;
		next = ft_strjoin(next, ft_duplicate(buf, 0, x));
		*buf = *ft_duplicate(buf, x + 1, 0);
		if (next[ft_strlen(next)] == '\n' )
			return (next);
		else
			bytes = read(fd, buf, BUFFER_SIZE);
	}
	if (next == NULL)
		return (NULL);
	return (next);
}
/*
char	*ft_save(char *buf, ssize_t x)
{
	ssize_t		y;
	char	new[BUFFER_SIZE + 1];

	y = 0;
	while (y <= x)
	{
		new[y] = buf[x + y];
		y++;
	}
	while (y <= BUFFER_SIZE + 1)
		new[y++] = '\0';
	return (ft_duplicate(new, 0, 0));
}
*/
