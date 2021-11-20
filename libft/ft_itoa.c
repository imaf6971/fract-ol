/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:32:37 by erayl             #+#    #+#             */
/*   Updated: 2021/10/10 17:22:38 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	long	i;
	size_t	len;
	long	ni;

	ni = (long) n;
	i = 10;
	len = 1;
	while (ni / i)
	{
		len++;
		i *= 10;
	}
	return (len);
}

static int	ft_minuscheck(int *n)
{
	int	minus;

	minus = 0;
	if (*n < 0)
	{
		*n *= -1;
		minus = 1;
	}
	return (minus);
}

static int	ft_mod(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	t;
	char	*a;
	size_t	nlen;
	size_t	minus;

	minus = ft_minuscheck(&n);
	nlen = ft_numlen(n);
	a = malloc((nlen + minus + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	if (minus)
		*a = '-';
	a[nlen + minus] = '\0';
	t = '0';
	while (nlen--)
	{
		t = ft_mod(n % 10) + '0';
		n /= 10;
		a[nlen + minus] = t;
	}
	return (a);
}
