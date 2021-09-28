/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:26:23 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/27 22:47:45 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	**check_arguments(char *command)
{
	int		pos;
	char	**result;

	pos = 0;
	while (command[pos])
	{
		if (command[pos] == '\"' && command[pos + 1] == ' '
			&& command[pos + 2] == '\"')
			command[pos + 1] = '|';
		pos++;
	}
	result = ft_split(command, ' ');
	pos = 0;
	while (result[pos])
	{
		if (ft_strncmp(result[pos], "\"|\"", 3) == 0)
			result[pos] = " ";
		pos++;
	}
	return (result);
}
