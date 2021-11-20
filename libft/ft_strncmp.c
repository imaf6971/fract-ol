/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:37:03 by erayl             #+#    #+#             */
/*   Updated: 2021/10/20 13:12:26 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	d1;
	unsigned char	d2;

	while (n--)
	{
		d1 = (unsigned char) *s1++;
		d2 = (unsigned char) *s2++;
		if (d1 != d2)
			return (d1 - d2);
		if (d1 == '\0')
			return (0);
	}
	return (0);
}
