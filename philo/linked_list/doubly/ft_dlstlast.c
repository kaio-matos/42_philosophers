/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:00:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/11 20:39:41 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	t_dlist	*current_list;

	if (!lst)
		return (NULL);
	current_list = lst;
	while (current_list->next)
		current_list = current_list->next;
	return (current_list);
}
