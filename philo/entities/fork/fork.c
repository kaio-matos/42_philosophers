/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:20:41 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/06 20:06:03 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_fork	*create_fork(int id, int philosopher_id)
{
	t_fork	*fork;

	fork = ft_salloc(sizeof(t_fork));
	fork->id = id;
	fork->philosopher_id = philosopher_id;
	fork->is_on_table = 0;
	return (fork);
}

t_fork	*get_fork(t_list *node)
{
	return ((t_fork *)node->content);
}
