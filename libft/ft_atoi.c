/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:08:05 by erayl             #+#    #+#             */
/*   Updated: 2021/11/20 18:01:20 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'
			|| *s == '\v' || *s == '\f' || *s == '\r'))
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s && ft_isdigit(*s))
	{
		result *= 10;
		result += *s - '0';
		s++;
	}
	return (result * sign);
}
