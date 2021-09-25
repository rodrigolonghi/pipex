/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:44:13 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/05/24 20:31:55 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_size;
	char	*temp;

	i = 0;
	temp = (char *)haystack;
	n_size = ft_strlen(needle);
	if (n_size == 0 || haystack == needle)
		return (temp);
	while (temp[i] != '\0' && i < len)
	{
		c = 0;
		while (temp[i + c] != '\0' && needle[c] != '\0'
			&& temp[i + c] == needle[c] && i + c < len)
			c++;
		if (c == n_size)
			return (temp + i);
		i++;
	}
	return (0);
}
