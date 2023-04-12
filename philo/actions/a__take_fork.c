/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a__take_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:43:03 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/11 21:14:13 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	a__take_fork(t_philosopher *philosopher, t_dlist *forks)
{
	t_dlist	*fork_node;
	t_dlist	*fork_next_node;

	fork_node = find_fork_node_by_philosopher_id(forks, philosopher->id);
	if (!fork_node)									// TODO: handle this error (it is needed?)
		return ;
	if (fork_node->next)							// TODO: handle cases that we don't find the next one (probably we will need to change our linked list to a circular linked list)
		fork_next_node = fork_node->next;
	else
		fork_next_node = forks;						// TEMP: Until we have circular linked lists
	if (!(get_fork(fork_node)->is_on_table && get_fork(fork_next_node)->is_on_table))
	{
		debug("%sa__take_fork: The philosopher %i tried to take a fork!%s\n", SHELL_R, philosopher->id, SHELL_RC);
		debug("%sa__take_fork: But the fork wasn't on the table, something has gone wrong!%s\n", SHELL_R, SHELL_RC);
		return ;
	}
	get_fork(fork_node)->is_on_table = FALSE;
	get_fork(fork_next_node)->is_on_table = FALSE;
	get_fork(fork_next_node)->philosopher_id = philosopher->id;
	log_taken_fork(philosopher);
}

void	a__put_forks_on_table(t_philosopher *philosopher, t_dlist *forks)
{
	t_dlist	*fork_node;
	t_dlist	*fork_to_return;

	fork_node = find_fork_node_by_philosopher_id(forks, philosopher->id);
	if (!fork_node)									// TODO: handle this error (it is needed?)
		return ;									// TODO: handle cases that we don't find the next one (probably we will need to change our linked list to a circular linked list)
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
		debug("a__put_forks_on_table: Something has gone terribly wrong\n\n");
		return ;
	}
	if (get_fork(fork_node)->is_on_table && get_fork(fork_to_return)->is_on_table)
	{
		debug("%sa__put_forks_on_table: The philosopher %i tried to return the fork to the table!%s\n", SHELL_R, philosopher->id, SHELL_RC);
		debug("%sa__put_forks_on_table: But the fork was already on the table, something has gone wrong!%s\n", SHELL_R, SHELL_RC);
		return ;
	}
	get_fork(fork_node)->is_on_table = TRUE;
	if (get_fork(fork_to_return)->philosopher_id == philosopher->id)
		get_fork(fork_to_return)->is_on_table = TRUE;
}
