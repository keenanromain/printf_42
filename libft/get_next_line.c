/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:29:37 by kromain           #+#    #+#             */
/*   Updated: 2017/03/21 10:30:09 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_previous(char **leftovers, char **line)
{
	char		*tmp;
	char		*swap;

	if ((tmp = ft_strchr(*leftovers, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*leftovers);
		swap = ft_strdup(tmp + 1);
		ft_strdel(leftovers);
		*leftovers = ft_strdup(swap);
		ft_strdel(&swap);
		tmp = NULL;
		return (1);
	}
	return (0);
}

int		check_current(char *buffer, char **leftovers, char **line)
{
	char		*tmp;
	char		*swap;

	if ((tmp = ft_strchr(buffer, '\n')))
	{
		*tmp = '\0';
		*line = ft_strjoin(*leftovers, buffer);
		swap = ft_strdup(tmp + 1);
		ft_strdel(leftovers);
		*leftovers = ft_strdup(swap);
		ft_strdel(&swap);
		tmp = NULL;
		ft_strdel(&buffer);
		return (1);
	}
	return (0);
}

int		find_return(int size, char *buffer, char **leftovers, char **line)
{
	if (size < 0)
		return (-1);
	ft_strdel(&buffer);
	if (**leftovers)
	{
		*line = ft_strdup(*leftovers);
		ft_strdel(leftovers);
		return (1);
	}
	*line = NULL;
	ft_strdel(leftovers);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char	*leftovers;
	char		*buffer;
	int			size;
	char		*swap;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (!leftovers)
		leftovers = ft_strnew(0);
	else if (check_previous(&leftovers, line))
		return (1);
	buffer = ft_strnew(BUFF_SIZE);
	while ((size = (read(fd, buffer, BUFF_SIZE))) > 0)
	{
		buffer[size] = '\0';
		if (check_current(buffer, &leftovers, line))
			return (1);
		swap = ft_strjoin(leftovers, buffer);
		ft_strdel(&leftovers);
		leftovers = ft_strdup(swap);
		ft_strdel(&swap);
	}
	return (find_return(size, buffer, &leftovers, line));
}
