/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   th__philosophers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:38:57 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/20 02:20:45 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

/**
 * When a philosopher has finished eating, they put their forks back on the table and
 * start sleeping. Once awake, they start thinking again. The simulation stops when
 * a philosopher dies of starvation.
*/
void	*th_philosopher_routine(void	*args_void)
{
	t_philosopher_routine	*args;
	int						i;
	t_using_forks			*using_forks;
	t_dlist					*own_fork_node;

	args = args_void;
	i = args->philosopher->times_to_eat;
	own_fork_node = find_fork_node_by_philosopher_id(args->forks, args->philosopher->id);
	args->philosopher->last_meal_ms = current_time_ms();
	while (i || args->philosopher->times_to_eat == -1)
	{
		if (!*args->is_simulation_running)
			break ;
		using_forks = a__take_fork(args, own_fork_node);
		if (!using_forks)
			break ;
		if (!*args->is_simulation_running)
			break ;
		args->philosopher->last_meal_ms = current_time_ms();
		a__eat(args);
		if (!*args->is_simulation_running)
		{
			pthread_mutex_unlock(using_forks->borrowed->mutex);
			pthread_mutex_unlock(using_forks->mine->mutex);
			free(using_forks);
			break ;
		}
		a__put_forks_on_table(using_forks);
		if (!*args->is_simulation_running)
			break ;
		a__sleep(args);
		if (!*args->is_simulation_running)
			break ;
		a__think(args->philosopher);
		if (!*args->is_simulation_running)
			break ;
		i--;
	}
	free(args);
	return (NULL);
}

void	th__create_philosophers_threads(
	t_list *philosophers,
	t_dlist *forks,
	const int *is_simulation_running,
	void *(*philosopher_routine)(void *)
)
{
	t_philosopher_routine	*philosopher_routine_args;

	while (philosophers)
	{
		philosopher_routine_args = ft_salloc(sizeof(t_philosopher_routine));
		philosopher_routine_args->philosopher = get_philosopher(philosophers);
		philosopher_routine_args->forks = forks;
		philosopher_routine_args->is_simulation_running = is_simulation_running;
		if (pthread_create(&get_philosopher(philosophers)->thread, NULL, philosopher_routine, philosopher_routine_args)) {
			printf("Error creating thread\n"); // TODO
		}
		philosophers = philosophers->next;
	}
}
