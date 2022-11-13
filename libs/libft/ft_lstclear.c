/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:42:18 by akazarya          #+#    #+#             */
/*   Updated: 2022/03/15 02:03:59 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*new;

	if (lst && del && *lst)
	{
		list = *lst;
		while (list)
		{
			new = list->next;
			(*del)(list->content);
			free(list);
			list = new;
		}
		*lst = NULL;
	}
}
