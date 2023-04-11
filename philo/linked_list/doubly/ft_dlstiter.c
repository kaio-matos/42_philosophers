/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:50:09 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/11 20:39:41 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	ft_dlstiter(t_dlist *lst, void (*f)(void *))
{
	t_dlist	*temp;

	if (!lst || !f)
		return ;
	temp = ft_dlstfirst(lst);
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}
