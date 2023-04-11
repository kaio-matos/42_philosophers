/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:15:20 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/11 20:39:41 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	ft_dlstclear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*temp;
	t_dlist	*current;

	if (!lst || !del)
		return ;
	current = (*lst)->prev;
	while (current)
	{
		temp = current->prev;
		ft_dlstdelone(current, del);
		current = temp;
	}
	current = (*lst)->next;
	while (current)
	{
		temp = current->next;
		ft_dlstdelone(current, del);
		current = temp;
	}
	ft_dlstdelone((*lst), del);
	*lst = NULL;
}
