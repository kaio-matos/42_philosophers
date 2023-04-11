/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a__take_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:43:03 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/11 20:32:49 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	a__take_fork(t_philosopher *philosopher, t_list *forks)
{
	t_list	*fork_node;
	t_list	*fork_next_node;

	fork_node = find_fork_node_by_philosopher_id(forks, philosopher->id);
	if (!fork_node)									// TODO: handle this error (it is needed?)
		return ;
	if (fork_node->next)							// TODO: handle cases that we don't find the next one (probably we will need to change our linked list to a circular linked list)
		fork_next_node = fork_node->next;
	else
	{
		debug("im falling here 1...\n\n");
		fork_next_node = forks;						// TEMP: Until we have circular linked lists
	}
	print_fork(get_fork(fork_node));
	print_fork(get_fork(fork_next_node));
	if (!get_fork(fork_next_node)->is_on_table)
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

void	a__put_forks_on_table(t_philosopher *philosopher, t_list *forks)
{
	t_list	*fork_node;
	t_list	*fork_next_node;

	fork_node = find_fork_node_by_philosopher_id(forks, philosopher->id);
	if (!fork_node)									// TODO: handle this error (it is needed?)
		return ;
	if (fork_node->next)							// TODO: handle cases that we don't find the next one (probably we will need to change our linked list to a circular linked list)
		fork_next_node = fork_node->next;
	else
	{
		debug("im falling here 2...\n\n");
		fork_next_node = forks;						// TEMP: Until we have circular linked lists
	}
	print_fork(get_fork(fork_node));
	print_fork(get_fork(fork_next_node));
	if (get_fork(fork_next_node)->is_on_table)
	{
		debug("%sa__put_forks_on_table: The philosopher %i tried to return the fork to the table!%s\n", SHELL_R, philosopher->id, SHELL_RC);
		debug("%sa__put_forks_on_table: But the fork was already on the table, something has gone wrong!%s\n", SHELL_R, SHELL_RC);
		return ;
	}
	get_fork(fork_node)->is_on_table = TRUE;
	if (get_fork(fork_next_node)->philosopher_id == philosopher->id)
		get_fork(fork_next_node)->is_on_table = TRUE;
}
