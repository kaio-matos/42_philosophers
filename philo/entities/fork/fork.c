/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:20:41 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/17 21:11:46 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_fork	*create_fork(int id, int philosopher_id)
{
	t_fork	*fork;

	fork = ft_salloc(sizeof(t_fork));
	fork->id = id;
	fork->philosopher_id = philosopher_id;
	fork->mutex = ft_salloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(fork->mutex, NULL);
	return (fork);
}

t_fork	*get_fork(t_dlist *node)
{
	if (!node)
		return (NULL);
	return ((t_fork *)node->content);
}
