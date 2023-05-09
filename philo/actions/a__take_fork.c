/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a__take_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:43:03 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/05/08 21:20:11 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_fork	*a__take_fork(t_philosopher_routine *args, t_dlist *fork_node)
{
	t_fork			*borrowed_fork;
	t_fork			*fork;

	fork = get_fork(fork_node);
	if (fork_node->next)
	{
		borrowed_fork = get_fork(fork_node->next);
		pthread_mutex_lock(fork->mutex);
		pthread_mutex_lock(borrowed_fork->mutex);
	}
	else if (get_fork(args->forks)->id != fork->id)
	{
		borrowed_fork = get_fork(args->forks);
		pthread_mutex_lock(borrowed_fork->mutex);
		pthread_mutex_lock(fork->mutex);
	}
	if (!is_simulation_running(args->simulation))
	{
		a__put_forks_on_table(fork, borrowed_fork);
		return (NULL);
	}
	log_taken_fork(args->philosopher, args->simulation);
	return (borrowed_fork);
}

void	a__put_forks_on_table(t_fork *mine, t_fork *borrowed)
{
	pthread_mutex_unlock(borrowed->mutex);
	pthread_mutex_unlock(mine->mutex);
}
