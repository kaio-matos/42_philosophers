/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:20:28 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/04 21:14:08 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temporary;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temporary = *lst;
		*lst = temporary->next;
		del(temporary->content);
		free(temporary);
	}
	*lst = NULL;
}
