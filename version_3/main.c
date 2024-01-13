/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:19:01 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/01/09 15:11:27 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;

	fd = open("file.txt", O_RDONLY);
	printf("1-LINE: %s", get_next_line(fd));
	printf("2-LINE: %s", get_next_line(fd));
	printf("3-LINE: %s", get_next_line(fd));
	printf("4-LINE: %s", get_next_line(fd));
	printf("5-LINE: %s", get_next_line(fd));
	printf("6-LINE: %s", get_next_line(fd));
	printf("7-LINE: %s", get_next_line(fd));
	printf("8-LINE: %s", get_next_line(fd));
	printf("9-LINE: %s", get_next_line(fd));
	printf("10-LINE: %s", get_next_line(fd));
	printf("11-LINE: %s", get_next_line(fd));
	printf("12-LINE: %s", get_next_line(fd));
	printf("13-LINE: %s", get_next_line(fd));
	printf("14-LINE: %s", get_next_line(fd));
	printf("15-LINE: %s", get_next_line(fd));
	printf("16-LINE: %s", get_next_line(fd));
	printf("17-LINE: %s", get_next_line(fd));
	printf("18-LINE: %s", get_next_line(fd));
	printf("19-LINE: %s", get_next_line(fd));
	printf("20-LINE: %s", get_next_line(fd));
	printf("\n");
	close(fd);
	return (0);
}

/*
	*/