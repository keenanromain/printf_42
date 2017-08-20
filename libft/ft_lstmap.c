/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 21:21:53 by kromain           #+#    #+#             */
/*   Updated: 2017/01/20 19:07:59 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list*))
{
	t_list	*result;
	t_list	*storage;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	if ((result = ft_lstnew(temp->content, temp->content_size)))
	{
		storage = result;
		lst = lst->next;
		while (lst)
		{
			temp = f(lst);
			if (!(storage->next = ft_lstnew(temp->content, temp->content_size)))
				return (NULL);
			storage = storage->next;
			lst = lst->next;
		}
	}
	return (result);
}
