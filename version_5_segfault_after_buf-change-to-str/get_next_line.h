/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:24:50 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/01/06 08:56:39 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

 #ifdef BUFFER_SIZE
 # define BUFSIZE BUFFER_SIZE
 #else
 # define BUFSIZE 10
 #endif

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <string.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>

char	*get_next_line(int fd);
int		ft_strlen(char *s);
char	*ft_read_fd(int fd, char *rest);
char	*ft_next(char *buf, char *next);
char	*ft_duplicate(char *str, int start, int end);
char	*ft_strjoin(char *base, char *add);
char	*ft_rest(char *buf);

#endif

