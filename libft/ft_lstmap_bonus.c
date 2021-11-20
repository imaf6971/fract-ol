/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:27:47 by erayl             #+#    #+#             */
/*   Updated: 2021/10/18 12:49:30 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*iter;

	map = (t_list *) malloc(sizeof(t_list));
	if (map == NULL)
		return (NULL);
	iter = map;
	while (lst)
	{
		iter->next = ft_lstnew(f(lst->content));
		if (iter->next == NULL)
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		iter = iter->next;
		lst = lst->next;
	}
	iter->next = NULL;
	iter = map->next;
	free(map);
	return (iter);
}
