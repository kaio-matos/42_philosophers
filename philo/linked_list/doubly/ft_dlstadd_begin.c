/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_begin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:20:28 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/11 20:39:41 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	ft_dlstadd_begin(t_dlist **lst, t_dlist *new)
{
	t_dlist	*first;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	first = ft_dlstfirst(*lst);
	first->prev = new;
	new->next = first;
}
