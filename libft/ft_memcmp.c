/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:42:00 by erayl             #+#    #+#             */
/*   Updated: 2021/10/09 15:57:31 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*uc1;
	const unsigned char	*uc2;
	unsigned char		d1;
	unsigned char		d2;

	uc1 = s1;
	uc2 = s2;
	while (n--)
	{
		d1 = *uc1++;
		d2 = *uc2++;
		if (d1 != d2)
			return (d1 - d2);
	}
	return (0);
}
