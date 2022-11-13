/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:08:41 by akazarya          #+#    #+#             */
/*   Updated: 2022/03/15 02:46:19 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tab;
	t_list	*new;

	tab = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			new = ft_lstnew((*f)(lst->content));
			if (!new)
			{
				ft_lstclear(&tab, del);
				ft_lstclear(&lst, del);
				break ;
			}
			ft_lstadd_back(&tab, new);
			lst = lst->next;
		}
	}
	return (tab);
}
