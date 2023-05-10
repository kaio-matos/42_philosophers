/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   th__philosophers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:38:57 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/05/09 21:59:47 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	th__philosopher_cycle(
				t_philosopher_routine *args,
				t_dlist *own_fork_node
				);

/**
 * When a philosopher has finished eating, they put their forks back on the
 * table and start sleeping. Once awake, they start thinking again.
 * The simulation stops when a philosopher dies of starvation.
*/
void	*th_philosopher_routine(void	*args_void)
{
	t_philosopher_routine	*args;
	t_dlist					*own_fork_node;

	args = args_void;
	own_fork_node = find_fork_node_by_philosopher_id(
			args->forks,
			args->philosopher->id
			);
	update_philosopher_last_meal(args->philosopher);
	if (args->philosopher->id % 2 == 0)
		usleep(1000);
	th__philosopher_cycle(args, own_fork_node);
	free(args);
	return (NULL);
}

void	th__create_philosophers_threads(
	t_list *philosophers,
	t_dlist *forks,
	t_simulation *simulation,
	void *(*philosopher_routine)(void *)
)
{
	t_philosopher_routine	*philosopher_routine_args;

	while (philosophers)
	{
		philosopher_routine_args = ft_salloc(sizeof(t_philosopher_routine));
		philosopher_routine_args->philosopher = get_philosopher(philosophers);
		philosopher_routine_args->forks = forks;
		philosopher_routine_args->simulation = simulation;
		if (pthread_create(
				&get_philosopher(philosophers)->thread,
				NULL,
				philosopher_routine,
				philosopher_routine_args
			))
		{
			free(philosopher_routine_args);
			printf("Error creating thread\n");
		}
		philosophers = philosophers->next;
	}
}

static void	th__philosopher_cycle(
	t_philosopher_routine *args,
	t_dlist *own_fork_node
)
{
	t_fork	*borrowed;
	int		i;

	i = args->philosopher->times_to_eat;
	borrowed = NULL;
	while (i || args->philosopher->times_to_eat == -1)
	{
		if (!is_simulation_running(args->simulation))
			break ;
		borrowed = a__take_fork(args, own_fork_node);
		if (!borrowed)
			break ;
		if (!is_simulation_running(args->simulation))
		{
			a__put_forks_on_table(get_fork(own_fork_node), borrowed);
			break ;
		}
		update_philosopher_last_meal(args->philosopher);
		a__eat(args);
		a__put_forks_on_table(get_fork(own_fork_node), borrowed);
		if (!is_simulation_running(args->simulation))
			break ;
		a__sleep(args);
		if (!is_simulation_running(args->simulation))
			break ;
		a__think(args);
		i--;
	}
}
