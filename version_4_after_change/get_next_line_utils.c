/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:24:37 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/01/12 17:03:15 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(char *s)
{
	ssize_t	len;

	len = 0;
	if (!s)
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
	if (end == -1)
		end = ft_strlen(str);
	if (end >= start)
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
	dup[count] = '\0';
	return (dup);
}

ssize_t	ft_strchr(char *s, ssize_t c)
{
	ssize_t		i;

	i = 0;
	if (!s)
		return (-2);
	else if (s[0] == c)
		return (0);
	else
	{
		while (s[i] != '\0')
		{
			if (s[i] == c)
				return (i);
			i++;
		}
	}
	return (-1);
}
