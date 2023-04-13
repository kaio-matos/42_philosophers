/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a__take_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:43:03 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/12 21:27:45 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int		a__take_fork(t_philosopher *philosopher, t_dlist *forks)
{
	t_dlist	*fork_node;
	t_dlist	*fork_next_node;
	t_fork	*borrowed_fork;
	int		lender_philosopher_id;

	fork_node = find_fork_node_by_philosopher_id(forks, philosopher->id);
	if (!fork_node)									// TODO: handle this error (it is needed?)
	{
		debug("%sa__take_fork: The philosopher %i tried to take a fork from the table!\na__take_fork: But couldn't find your own fork!%s\n", SHELL_R, philosopher->id, SHELL_RC);
		return (FALSE);
	}
	if (fork_node->next)							// TODO: handle cases that we don't find the next one (probably we will need to change our linked list to a circular linked list)
		fork_next_node = fork_node->next;
	else if (get_fork(fork_node)->id == get_fork(forks)->id)
	{
		debug("%sa__take_fork: The philosopher %i tried to take a fork from the table!\na__take_fork: But actually the fork he tried to take it was his own!%s\n", SHELL_R, philosopher->id, SHELL_RC);
		return (FALSE);
	}
	else
		fork_next_node = forks;						// TEMP: Until we have circular linked lists
	if (!(get_fork(fork_node)->is_on_table && get_fork(fork_next_node)->is_on_table))
	{
		debug("%sa__take_fork: The philosopher %i tried to take a fork from the table!\na__take_fork: But the fork wasn't on the table!%s\n", SHELL_R, philosopher->id, SHELL_RC);
		return (FALSE);
	}
	get_fork(fork_node)->is_on_table = FALSE;
	get_fork(fork_next_node)->is_on_table = FALSE;
	lender_philosopher_id = get_fork(fork_next_node)->philosopher_id;
	if (!a__borrow_fork(philosopher, get_fork(fork_next_node)))
	{
		debug("%sa__take_fork: The philosopher %i tried to take a fork from the table!\na__take_fork: But actually the fork he tried to take it was his own!%s\n", SHELL_R, philosopher->id, SHELL_RC);
		return (FALSE);
	}
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

void	a__put_forks_on_table(t_philosopher *philosopher, t_dlist *forks, int lender_philosopher_id)
{
	t_dlist	*fork_node;
	t_dlist	*fork_to_return;

	fork_node = find_fork_node_by_philosopher_id(forks, philosopher->id);
	if (!fork_node)									// TODO: handle this error (it is needed?)
	{
		debug("%sa__put_forks_on_table: The philosopher %i tried to return to the table your own fork!\na__take_fork: But couldn't find it!%s\n", SHELL_R, philosopher->id, SHELL_RC);
		return ;									// TODO: handle cases that we don't find the next one (probably we will need to change our linked list to a circular linked list)
	}
	if (
		fork_node->next &&
		get_fork(fork_node->next)->philosopher_id == philosopher->id
	)
		fork_to_return = fork_node->next;
	else if (
		fork_node->prev &&
		get_fork(fork_node->prev)->philosopher_id == philosopher->id
	)
		fork_to_return = fork_node->prev;
	else if (
		ft_dlstlast(fork_node) &&
		get_fork(ft_dlstlast(fork_node))->philosopher_id == philosopher->id &&
		get_fork(ft_dlstlast(fork_node))->id != get_fork(fork_node)->id
	)
		fork_to_return = ft_dlstlast(fork_node);
	else
	{
		debug("%sa__put_forks_on_table: Something has gone terribly wrong\n\n%s", SHELL_R, SHELL_RC);
		return ;
	}
	if (get_fork(fork_node)->is_on_table && get_fork(fork_to_return)->is_on_table)
	{
		debug("%sa__put_forks_on_table: The philosopher %i tried to return the fork to the table!%s\n", SHELL_R, philosopher->id, SHELL_RC);
		debug("%sa__put_forks_on_table: But the fork was already on the table, something has gone wrong!%s\n", SHELL_R, SHELL_RC);
		return ;
	}
	get_fork(fork_node)->is_on_table = TRUE;
	get_fork(fork_to_return)->is_on_table = TRUE;
	get_fork(fork_to_return)->philosopher_id = lender_philosopher_id;
	if (get_fork(fork_to_return)->philosopher_id == philosopher->id)
		get_fork(fork_to_return)->is_on_table = TRUE;
}
