/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:16:41 by kromain           #+#    #+#             */
/*   Updated: 2017/01/19 00:15:36 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *traversing_node;
	t_list *following_node;

	following_node = *alst;
	while (following_node)
	{
		traversing_node = following_node->next;
		del(following_node->content, following_node->content_size);
		free(following_node);
		following_node = traversing_node;
	}
	*alst = NULL;
}
