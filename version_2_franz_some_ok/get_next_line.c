/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:08:25 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/01/11 02:12:56 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		if (ft_buf(fd) != NULL)
			return (ft_buf(fd));
		else
			return (free(ft_buf(fd)), NULL);
	}
	return (NULL);
}
