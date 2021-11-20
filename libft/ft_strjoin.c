/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:33:36 by erayl             #+#    #+#             */
/*   Updated: 2021/10/10 16:54:14 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	s1len;
	size_t	s2len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	join = (char *) malloc((s1len + s2len + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	ft_memcpy(join, s1, s1len);
	ft_memcpy(join + s1len, s2, s2len);
	join[s1len + s2len] = '\0';
	return (join);
}
