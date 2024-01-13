/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:11:07 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/01/09 18:29:37 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(char *s)
{
	ssize_t	len;

	len = 0;
	if (!s)
		return (0);
	if (s[0] == '\0')
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
	if (!base)
	{
		if (!add)
			return (NULL);
		return (add);
	}
	if (!add)
		return (base);
	len = ft_strlen(base) + ft_strlen(add) + 1;
	join = malloc(sizeof(char) * len);
	if (!join)
		return (NULL);
	while (i <= len)
	{
	   if (i < ft_strlen(base) && base[i] != '\0')
		   join[i] = base[i];
	   else if (i > ft_strlen(base) && i <= len)
	   {
		   join[i] = add[j];
		   j++;
	   }
	   i++;
	}
	return (join);
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
	while (count <= len)
	{
		dup[count] = str[start];
		start++;
		count++;
	}
	return (dup);
}

char	*ft_buf(int fd, char *next)
{
	ssize_t		bytes;
	static char	buf[BUFFER_SIZE + 1];
	char		*temp;
	ssize_t		x;

	if (buf[0] == '\0')
		bytes = read(fd, buf, BUFFER_SIZE);
	while (bytes > 0 && next[ft_strlen(next) - 1] != '\n')
	{
		temp = NULL;
		buf[bytes + 1] = '\0';
		x = 0;
		while (buf[x] != '\0' && buf[x] != '\n')
			x++;
		temp = ft_strjoin(next, ft_duplicate(buf, 0, x));
		next = NULL;
		next = ft_duplicate(temp, 0, -1);
		bytes = -1;
		while (buf[x + 1] != '\0' && x <= BUFFER_SIZE)
		{
			x++;
			bytes++;
			buf[bytes] = buf[x];
		}
		if (bytes == 0)
			bytes = read(fd, buf, BUFFER_SIZE);
		buf[bytes + 1] = '\0';
	}
	temp = NULL;
	return (free(temp), next);
}

