/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:37:58 by erayl             #+#    #+#             */
/*   Updated: 2021/10/10 16:53:16 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_trimlen(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;

	while (isinset(*s1, set))
		s1++;
	start = s1;
	while (*s1)
		s1++;
	s1--;
	while (isinset(*s1, set) && s1 >= start)
		s1--;
	s1++;
	end = s1;
	return (end - start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	trimlen;
	size_t	start;

	if (s1 == NULL || set == NULL)
		return (NULL);
	trimlen = ft_trimlen(s1, set);
	start = 0;
	while (isinset(s1[start], set))
		start++;
	trim = ft_substr(s1, start, trimlen);
	if (trim == NULL)
		return (NULL);
	return (trim);
}
