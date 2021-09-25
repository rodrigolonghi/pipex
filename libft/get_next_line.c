/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 00:32:11 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/08 19:42:31 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_remove_nl(char **save, char **line)
{
	char	*temp;
	int		size;

	size = 0;
	while ((*save)[size] != '\0' && (*save)[size] != '\n')
		size++;
	if ((*save)[size] == '\0')
	{
		*line = ft_strdup(*save);
		if (*save != NULL)
		{
			free(*save);
			*save = NULL;
		}
		return (0);
	}
	*line = ft_substr(*save, 0, size);
	temp = ft_strdup((*save) + size + 1);
	free(*save);
	*save = temp;
	return (1);
}

static int	ft_result(char **save, char **line, ssize_t size)
{
	if (size == -1 || !line)
		return (-1);
	if (*save == NULL && size == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (ft_remove_nl(save, line));
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	char		*temp;
	ssize_t		size;

	buf = malloc(2);
	size = read(fd, buf, 1);
	while (size > 0)
	{
		buf[size] = '\0';
		if (!save)
			save = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(save, buf);
			free(save);
			save = temp;
		}
		if (ft_strchr(save, '\n'))
			break ;
		size = read(fd, buf, 1);
	}
	free(buf);
	return (ft_result(&save, line, size));
}
