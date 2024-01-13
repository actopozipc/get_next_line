/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:24:37 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/01/06 09:16:27 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s || s == NULL)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_duplicate(char *str, int start, int end)
{
	char	*dup;
	int		len;
	int		count;

	if (end == -1)
		end = ft_strlen(str);
	end += 1;
	if (end > start)
		len = end - start;
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
	dup[count] = '\0';
	return (dup);
}

char	*ft_strjoin(char *base, char *add)
{
	int		total;
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = 0;
	if (! base)
	{
		if (!add)
			return (NULL);
		return (add);
	}
	else if (!add)
		return (base);
	total = ft_strlen(base) + ft_strlen(add) + 1;
	join = malloc(sizeof(char) * total);
	if (!join)
		return (NULL);
	while (i < ft_strlen(base))
	{
		join[i] = base[i];
		i++;
	}
	while (j < ft_strlen(add) && i < total)
	{
		join[i] = add[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_read_fd(int fd, char *rest)
{
	int		bytes;
	char	*buffer;

	buffer = NULL;
	if (rest != NULL)
	{
		buffer = ft_duplicate(rest, 0, -1);
		rest = NULL;
	}
	else
	{
		buffer = malloc(sizeof(char) * (BUFSIZE + 1));
		if (!buffer)
			return (NULL);
		bytes = read(fd, buffer, BUFSIZE);
		if (bytes <= 0)
			return (NULL);
		buffer[bytes + 1] = '\0';
	}
	return (rest = NULL, buffer);
}

