/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:01:25 by erayl             #+#    #+#             */
/*   Updated: 2021/10/09 16:24:25 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*dup;
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s);
	dup = (char *) malloc((slen + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
