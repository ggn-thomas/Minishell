/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:20:02 by thomas            #+#    #+#             */
/*   Updated: 2024/10/17 17:08:56 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*list;
	t_list	*obj;

	if (!lst || !f || !del)
		return (NULL);
	list = NULL;
	while (lst)
	{
		obj = ft_lstnew(f(lst->content));
		if (!obj)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, obj);
		lst = lst->next;
	}
	return (list);
}
