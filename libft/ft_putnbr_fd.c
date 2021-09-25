/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:24:56 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/05/27 23:41:40 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_set_number(int n, int column, int fd)
{
	char	number;

	number = 'x';
	if (n < 0)
	{
		number = (n % 10) * (-1) + '0';
		if (column == 0)
			ft_putchar_fd('-', fd);
	}
	else if (!(n == 0 && column != 0))
		number = n % 10 + '0';
	return (number);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	digit[11];
	int		column;

	column = 0;
	while (column < 10)
	{
		digit[column] = ft_set_number(n, column, fd);
		n /= 10;
		column++;
	}
	column = 9;
	while (column >= 0)
	{
		if (digit[column] != 'x')
			ft_putchar_fd(digit[column], fd);
		column--;
	}
}
