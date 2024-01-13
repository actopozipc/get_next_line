/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:08:25 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/01/09 18:08:52 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*next;

	next = NULL;
	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		next = ft_buf(fd, next);
		if (next == NULL)
			return (free(next), NULL);
		else
			return (next);
	}
	else
		return (NULL);
}
