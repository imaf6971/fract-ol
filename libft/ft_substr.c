/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:12:01 by erayl             #+#    #+#             */
/*   Updated: 2021/10/21 09:46:01 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	actual_len;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	actual_len = ft_strlen(s + start);
	if (actual_len < len)
		len = actual_len;
	substr = (char *) malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	if (len != 0)
		ft_memcpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}
