/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 02:41:12 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/06/01 03:25:38 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		i = 1;
	else if (start + len > ft_strlen(s))
		i = ft_strlen(s) - start + 1;
	else
		i = len + 1;
	substring = (char *)ft_calloc(i, sizeof(char));
	if (!substring)
		return (NULL);
	if (i > 1)
	{
		i = 0;
		while (i < len && s[start + i] != '\0')
		{
			substring[i] = s[start + i];
			i++;
		}
	}
	return (substring);
}
