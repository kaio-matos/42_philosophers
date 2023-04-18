/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a__take_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:43:03 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/17 21:14:53 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_using_forks	*a__take_fork(t_philosopher *philosopher, t_dlist *forks)
{
	t_dlist	*fork_node;
	t_fork	*borrowed_fork;
	t_fork	*fork;
	t_using_forks	*using_forks;

	using_forks = ft_salloc(sizeof(t_using_forks));
	fork_node = find_fork_node_by_philosopher_id(forks, philosopher->id);
	while (!fork_node)
		fork_node = find_fork_node_by_philosopher_id(forks, philosopher->id);
	fork = get_fork(fork_node);
	if (fork_node->next)
		borrowed_fork = get_fork(fork_node->next);
	else if (fork->id == get_fork(forks)->id)
	{
		debug("%sa__take_fork: The philosopher %i tried to take a fork from the table!\na__take_fork: But actually the fork he tried to take it was his own!%s\n", SHELL_R, philosopher->id, SHELL_RC);
		return (NULL);
	}
	else
		borrowed_fork = get_fork(forks);
	if (fork->id == borrowed_fork->id)
		debug("%sa__take_fork: The philosopher %i ranned into a deadlock situation\n", SHELL_R, philosopher->id, SHELL_RC);
	pthread_mutex_lock(fork->mutex);
	pthread_mutex_lock(borrowed_fork->mutex);
	using_forks->mine = fork;
	using_forks->borrowed = borrowed_fork;
	log_taken_fork(philosopher);
	return (using_forks);
}

t_fork	*a__borrow_fork(t_philosopher *philosopher, t_fork *fork)
{
	if (philosopher->id == fork->philosopher_id)
		return (NULL);
	fork->philosopher_id = philosopher->id;
	return (fork);
}

void	a__put_forks_on_table(t_philosopher *philosopher, t_dlist *forks, t_using_forks *using_forks)
{
	pthread_mutex_unlock(using_forks->borrowed->mutex);
	pthread_mutex_unlock(using_forks->mine->mutex);
	free(using_forks);
	// debug("%s%ld\t %i has returned a fork%s\n", SHELL_BK, get_program_time(), philosopher->id, SHELL_RC);
}
