/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:12:38 by erayl             #+#    #+#             */
/*   Updated: 2021/10/20 14:11:06 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	const char	*p;
	char		ts;

	p = arr;
	ts = c;
	while (n--)
	{
		if (*p == ts)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
