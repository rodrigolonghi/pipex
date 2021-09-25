/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 04:30:31 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/06/01 03:55:04 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_start(char const *s1, char const *set)
{
	int	i;
	int	start;

	start = 0;
	i = 0;
	while (set[i] != '\0')
	{
		if (s1[start] == set[i])
		{
			start++;
			i = 0;
		}
		else
			i++;
	}
	return (start);
}

static int	ft_find_end(char const *s1, char const *set)
{
	int	i;
	int	size;

	size = ft_strlen(s1) - 1;
	i = 0;
	while (set[i])
	{
		while (s1[size] == set[i] && size >= 0)
		{
			size--;
			i = 0;
			continue ;
		}
		i++;
	}
	return (size + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		size;

	if (!s1 || !set)
		return (NULL);
	s1 += ft_find_start(s1, set);
	size = ft_find_end(s1, set);
	str = (char *)ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, size);
	return (str);
}
