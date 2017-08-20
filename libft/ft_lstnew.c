/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:40:44 by kromain           #+#    #+#             */
/*   Updated: 2017/01/18 20:34:21 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *copy;

	if (!(copy = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		copy->content_size = 0;
		copy->content = NULL;
	}
	else
	{
		if (!(copy->content = malloc(sizeof(content))))
			return (NULL);
		copy->content = ft_memcpy(copy->content, content, content_size);
		copy->content_size = content_size;
	}
	copy->next = NULL;
	return (copy);
}
