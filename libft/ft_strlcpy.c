/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:22:21 by erayl             #+#    #+#             */
/*   Updated: 2021/10/09 16:22:29 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	if (dstsize != 0)
	{
		while (dstsize - 1 > 0 && *src)
		{
			*dst++ = *src++;
			dstsize--;
		}
		*dst = '\0';
	}
	return (srclen);
}
