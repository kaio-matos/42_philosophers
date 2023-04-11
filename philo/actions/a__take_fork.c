/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a__take_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:43:03 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/11 20:08:33 by kmatos-s         ###   ########.fr       */
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
		fork_next_node = forks;						// TEMP: Until we have circular linked lists
	if (!get_fork(fork_next_node)->is_on_table)
	{
		debug("%sa__take_fork: The fork is not on the table, the order is wrong!%s\n", SHELL_R, SHELL_RC);
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
		fork_next_node = forks;						// TEMP: Until we have circular linked lists
	if (get_fork(fork_next_node)->is_on_table)
	{
		debug("%sa__put_forks_on_table: The fork is on the table, the order is wrong!%s\n", SHELL_R, SHELL_RC);
		return ;
	}
	get_fork(fork_node)->is_on_table = TRUE;
	if (get_fork(fork_next_node)->philosopher_id == philosopher->id)
		get_fork(fork_next_node)->is_on_table = TRUE;
}
