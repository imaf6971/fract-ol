/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:56:15 by erayl             #+#    #+#             */
/*   Updated: 2021/10/18 11:21:27 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;
	char	tw;

	ln = n;
	tw = '0';
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln = -ln;
	}
	if (ln >= 10)
	{
		ft_putnbr_fd(ln / 10, fd);
		tw = ln % 10 + '0';
		write(fd, &tw, 1);
	}
	if (ln < 10)
	{
		tw = ln % 10 + '0';
		write(fd, &tw, 1);
	}
}
