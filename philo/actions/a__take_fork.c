/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a__take_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:43:03 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/13 21:53:48 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int		a__take_fork(t_philosopher *philosopher, t_dlist *forks, pthread_mutex_t *mutex)
{
	t_dlist	*fork_node;
	t_dlist	*fork_next_node;
	t_fork	*borrowed_fork;
	t_fork	*fork;
	int		lender_philosopher_id;

	fork_node = find_fork_node_by_philosopher_id(forks, philosopher->id);
	while (!fork_node)
		fork_node = find_fork_node_by_philosopher_id(forks, philosopher->id);
	fork = get_fork(fork_node);
	if (fork_node->next)
		borrowed_fork = get_fork(fork_node->next);
	else if (get_fork(fork_node)->id == get_fork(forks)->id)
	{
		debug("%sa__take_fork: The philosopher %i tried to take a fork from the table!\na__take_fork: But actually the fork he tried to take it was his own!%s\n", SHELL_R, philosopher->id, SHELL_RC);
		return (FALSE);
	}
	else
		borrowed_fork = get_fork(forks);
	while (fork->is_on_table == FALSE || borrowed_fork->is_on_table == FALSE)
	{
	}
	pthread_mutex_lock(mutex);
	fork->is_on_table = FALSE;
	borrowed_fork->is_on_table = FALSE;
	lender_philosopher_id = borrowed_fork->philosopher_id;
	borrowed_fork->philosopher_id = philosopher->id;
	pthread_mutex_unlock(mutex);
	log_taken_fork(philosopher);
	return (lender_philosopher_id);
}

t_fork	*a__borrow_fork(t_philosopher *philosopher, t_fork *fork)
{
	if (philosopher->id == fork->philosopher_id)
		return (NULL);
	fork->philosopher_id = philosopher->id;
	return (fork);
}

void	a__put_forks_on_table(t_philosopher *philosopher, t_dlist *forks, int lender_philosopher_id, pthread_mutex_t *mutex)
{
	t_dlist	*fork_node;
	t_dlist	*fork_to_return;

	fork_node = find_fork_node_by_philosopher_id(forks, philosopher->id);
	if (!fork_node)
	{
		debug("%sa__put_forks_on_table: The philosopher %i tried to return to the table your own fork!\na__take_fork: But couldn't find it!%s\n", SHELL_R, philosopher->id, SHELL_RC);
		return ;
	}
	if (
		fork_node->next &&
		get_fork(fork_node->next)->philosopher_id == philosopher->id
	)
		fork_to_return = fork_node->next;
	else if (
		forks &&
		get_fork(forks)->philosopher_id == philosopher->id
	)
		fork_to_return = forks;
	else
	{
		debug("%sa__put_forks_on_table: The philosopher %i couldn't find the borrowed fork from %i lender philosopher!\n\n%s", SHELL_R, philosopher->id, lender_philosopher_id, SHELL_RC);
		return ;
	}
	if (get_fork(fork_node)->is_on_table || get_fork(fork_to_return)->is_on_table)
	{
		debug("%sa__put_forks_on_table: The philosopher %i tried to return the fork to the table!%s\n", SHELL_R, philosopher->id, SHELL_RC);
		debug("%sa__put_forks_on_table: But the fork was already on the table, something has gone wrong!%s\n", SHELL_R, SHELL_RC);
		return ;
	}
	pthread_mutex_lock(mutex);
	get_fork(fork_node)->is_on_table = TRUE;
	get_fork(fork_to_return)->is_on_table = TRUE;
	get_fork(fork_to_return)->philosopher_id = lender_philosopher_id;
	pthread_mutex_unlock(mutex);
}
