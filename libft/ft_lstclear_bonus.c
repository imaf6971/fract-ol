/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:57:32 by erayl             #+#    #+#             */
/*   Updated: 2021/10/18 12:48:04 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*next;

	next = *lst;
	curr = *lst;
	while (curr)
	{
		next = next->next;
		del(curr->content);
		free(curr);
		curr = next;
	}
	*lst = NULL;
}
