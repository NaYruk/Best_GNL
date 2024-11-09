/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:28:20 by marcmilliot       #+#    #+#             */
/*   Updated: 2024/11/09 17:35:00 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
int		search_new_line(char *stock);
char	*ft_strjoin(char *buff, char *stock);
char	*get_next_line(int fd);
char	*free_stock(char **stock);
void	put_buff_stock_in_new_stock(char **new_stock, char *stock, char *buff);
char	*get_malloc_new_stock(char **stock, char *buff);

#endif