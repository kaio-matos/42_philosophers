/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a__take_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:43:03 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/18 21:15:16 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_using_forks	*a__take_fork(t_philosopher_routine *args)
{
	t_dlist	*fork_node;
	t_fork	*borrowed_fork;
	t_fork	*fork;
	t_using_forks	*using_forks;

	using_forks = ft_salloc(sizeof(t_using_forks));
	fork_node = find_fork_node_by_philosopher_id(args->forks, args->philosopher->id);
	while (!fork_node)
		fork_node = find_fork_node_by_philosopher_id(args->forks, args->philosopher->id);
	fork = get_fork(fork_node);
	if (fork_node->next)
		borrowed_fork = get_fork(fork_node->next);
	else if (fork->id == get_fork(args->forks)->id)
	{
		free(using_forks);
		return (NULL);
	}
	else
		borrowed_fork = get_fork(args->forks);
	if (fork->id == borrowed_fork->id)
		debug("%sa__take_fork: The philosopher %i ranned into a deadlock situation\n", SHELL_R, args->philosopher->id, SHELL_RC);
	pthread_mutex_lock(fork->mutex);
	pthread_mutex_lock(borrowed_fork->mutex);
	using_forks->mine = fork;
	using_forks->borrowed = borrowed_fork;
	if (!*args->is_simulation_running)
	{
		pthread_mutex_unlock(using_forks->borrowed->mutex);
		pthread_mutex_unlock(using_forks->mine->mutex);
		free(using_forks);
		return (NULL);
	}
	log_taken_fork(args->philosopher);
	return (using_forks);
}

void	a__put_forks_on_table(t_using_forks *using_forks)
{
	pthread_mutex_unlock(using_forks->borrowed->mutex);
	pthread_mutex_unlock(using_forks->mine->mutex);
	free(using_forks);
}
