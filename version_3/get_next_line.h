/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:08:55 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/01/11 07:22:40 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <string.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <time.h>

char	*get_next_line(int fd);
ssize_t	ft_strlen(char *s);
char	*ft_strjoin(char **base, char *add);
char	*ft_duplicate(char *str, ssize_t start, ssize_t end);
char	*ft_buf(int fd);
char	*ft_save(char *buf, int x);

#endif
