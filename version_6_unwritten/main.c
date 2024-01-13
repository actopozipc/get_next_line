/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:06:21 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/01/12 12:11:02 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int	fd;

fd1 = empty file
fd2 = emptyfile + nL
f3 = only 2 tabs in 5th line, no nL at end
f4 = >10000 chars
f5 = 50000 chars
f6 = 100000 chars
f7 = alternating nL no nL in different 
f8 = lines around 10
f9 = 42ish stuff
f10 = eof with nl
f11 = eof no nl
f12 = size of length of lines varies a lot (1- 200- 25- 1498- 2)...

also: BUFFER_SIZE -> define but also ut in main and sometimes forget about it!

stdin etc!!
*/

#include "get_next_line.h"

#define BUFFER_SIZE 13
 
int	main(void)
{
	time_t	start;
	time_t	end;
	int		fd;
	int		x;
	double	diff;
	ssize_t	buf_start;
	ssize_t	buf_end;
	ssize_t	difference;

	time (&start);
	x = 0;
	buf_start = BUFFER_SIZE;
	fd = open("file.txt", O_RDONLY);
	if (fd >= 0)
	{
		printf("validated FD: %d[nl]\n", fd);
		if (get_next_line(fd) != NULL)
			printf("-> fd recognized correctly![nl]\n");
		else if (get_next_line(fd) == NULL)
			printf("...correct fd was not recognized.[nl]\n");
	}
	else
	{
		printf("INVALID FD: %d[nl]\n", fd);
		if (get_next_line(fd) == NULL)
			printf("fd: recognized &managed![nl]\n");
		else
			printf("FAILED![nl]\n");
	}
	while (get_next_line(fd) != NULL && x < 20)
	{
		printf("LINE: %s", get_next_line(fd));
		x++;
	}
	char	*save1 = get_next_line(fd);
	if (save1 != NULL)
		printf("Failed first NULL-LINE. (EOF already reached)[nl]\nOutput: %s[nl]\n", save1);
	else
		printf("First NULL-LINE: ok![nl]\n");
	char	*save2 = get_next_line(fd);
	if (save2 != NULL)
		printf("Failed second NULL-LINE. (EOF already reached)[nl]\nOutput: %s[nl]\n", save2);
	else
		printf("Second NULL-LINE: ok![nl]\n");
	printf("[nl][nl]\n\n");
	buf_end = BUFFER_SIZE;
	difference = buf_end - buf_start;
	if (difference == 0 && BUFFER_SIZE > 0)
		printf("Validated BUFFER_SIZE was recognized &used correctly![nl]\n");
	else
	{
		printf("Error in BUFFERSIZE:[nl]\n");
		if (difference != 0)
		{
			printf("Modified amount of bytes to read at once.[nl]\n");
			printf("difference(end-startsize): %ld[nl]\nShould have been: %ld[nl]\n", difference, BUFFER_SIZE);
		}
		if (BUFFER_SIZE <= 0 && get_next_line(fd) != NULL)
		{
			printf("Failed case 'BUFFER_SIZE too small'.[nl]\nNo Error Management detected.[nl]\n");
			printf("actual BUFFER_SIZE: %ld[nl]\n", BUFFER_SIZE);
		}
	}
	close(fd);
	time (&end);
	diff = difftime (end, start);
	printf ("[nl]\ntime: %0.2lf seconds[nl]\n", diff);
	return (0);
}

/*
#include "get_next_line.h"

int	main(void)
{
	time_t	start;
	time_t	end;
	int		fd;
	double	diff;

	time (&start);
	fd = open("file.txt", O_RDONLY);
	printf("BUFFER_SIZE: %d[nl]\n", BUFFER_SIZE);
	printf("FD: %d[nl]\n", fd);
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
	printf("[nl]\n");
	close(fd);
	time (&end);
	diff = difftime (end, start);
	printf ("[nl]\ntime: %.9lf seconds[nl]\n", diff);
	return (0);
}
*/