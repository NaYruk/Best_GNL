/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:30:25 by marcmilliot       #+#    #+#             */
/*   Updated: 2024/11/09 03:26:30 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_stock(char *stock, int fd)
{
	ssize_t	value_read;
	char	*buff;

	value_read = 1;
	while (!search_new_line(stock) && value_read > 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		value_read = read(fd, buff, BUFFER_SIZE);
		if (value_read <= 0)
		{
			free(buff);
			if (value_read == -1 && stock != NULL)
				free_stock(&stock);
			return (stock);
		}
		buff[value_read] = '\0';
		stock = ft_strjoin(buff, stock);
		if (!stock)
			return (NULL);
		free(buff);
	}
	return (stock);
}

static char	*get_final_line(char *stock)
{
	char	*final_line;
	size_t	i;

	i = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	if (stock[i] == '\n')
		i++;
	final_line = malloc(sizeof(char) * (i + 1));
	if (!final_line)
	{
		free_stock(&stock);
		return (NULL);
	}
	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
	{
		final_line[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
		final_line[i++] = '\n';
	final_line[i] = '\0';
	return (final_line);
}

static void	update_stock(char **stock)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	temp = NULL;
	while ((*stock)[i] != '\n' && (*stock)[i] != '\0')
		i++;
	if ((*stock)[i] == '\n')
		i++;
	temp = malloc(sizeof(char) * (ft_strlen(*stock) - i + 1));
	if (!temp)
	{
		free_stock(stock);
		return ;
	}
	while ((*stock)[i] != '\0')
		temp[j++] = (*stock)[i++];
	temp[j] = '\0';
	free(*stock);
	(*stock) = temp;
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*final_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = read_and_stock(stock, fd);
	if (stock == NULL)
		return (NULL);
	final_line = get_final_line(stock);
	if (final_line == NULL)
		return (NULL);
	update_stock(&stock);
	if (stock == NULL)
		return (NULL);
	if (stock[0] == '\0')
	{
		free(stock);
		stock = NULL;
		return (final_line);
	}
	return (final_line);
}
