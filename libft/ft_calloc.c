/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:28:31 by erayl             #+#    #+#             */
/*   Updated: 2021/10/08 18:27:39 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*alctd_mem;
	char			*p;
	size_t			alctd_size;

	alctd_size = count * size;
	alctd_mem = malloc(alctd_size);
	if (alctd_mem == NULL)
		return (NULL);
	p = alctd_mem;
	while (alctd_size--)
		*p++ = 0;
	return (alctd_mem);
}
