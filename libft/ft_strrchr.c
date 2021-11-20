/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:24:05 by erayl             #+#    #+#             */
/*   Updated: 2021/10/20 14:15:07 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	*result;
	char	ts;

	result = NULL;
	ts = c;
	while (*s)
	{
		if (*s == ts)
			result = s;
		s++;
	}
	if (*s == ts)
		result = s;
	return (result);
}
