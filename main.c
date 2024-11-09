/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 01:47:29 by marcmilliot       #+#    #+#             */
/*   Updated: 2024/11/09 16:08:56 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	size_t	i;

	fd = 0;
    	line = NULL;
	line = get_next_line(fd);
	i = 0;
	/*while(line[i] != '\0')						// test pour stdin.
	{
		if (line[i] == '\n')
			printf("/n");
		printf("%c", line[i]);
		i++;
	}
	free(line);*/
	if (argc < 2)
	{
		printf("Il manque le fichier a lire");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Le fichier n'a pas pu etre ouvert !");
		return (0);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		i = 0;
		while(line[i] != '\0')
		{
			if (line[i] == '\n')
				printf("/n");
			printf("%c", line[i]);
			i++;
		}
		free(line);
	}
	close(fd);
	return (0);
}
