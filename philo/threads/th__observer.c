/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   th__observer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:38:57 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/05/09 21:41:16 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	th_observer_cycle(t_observer_routine *args);

void	*th_observer_routine(void	*args_void)
{
	t_observer_routine	*args;

	args = args_void;
	if (!args->philosophers->next)
	{
		pthread_mutex_lock(args->simulation->mutex);
		args->simulation->is_simulation_running = FALSE;
		pthread_mutex_unlock(args->simulation->mutex);
		usleep(1000);
		log_death(get_philosopher(args->philosophers), args->simulation);
		free(args_void);
		return (NULL);
	}
	th_observer_cycle(args);
	free(args_void);
	return (NULL);
}

void	th__create_observer(
			t_list *philosophers,
			t_simulation *simulation,
			pthread_t *thread
			)
{
	t_observer_routine	*observer_routine_args;

	observer_routine_args = ft_salloc(sizeof(t_observer_routine));
	observer_routine_args->philosophers = philosophers;
	observer_routine_args->simulation = simulation;
	if (pthread_create(
			thread,
			NULL,
			th_observer_routine,
			observer_routine_args))
	{
		free(observer_routine_args);
		printf("Error creating thread\n");
	}
}

static void	th_observer_cycle(t_observer_routine *args)
{
	t_list	*philosophers_temp;

	philosophers_temp = args->philosophers;
	while (TRUE)
	{
		if (are_philosophers_satisfied(philosophers_temp))
			break ;
		if (is_philosopher_dead(
				get_philosopher(args->philosophers),
				args->simulation
			))
			break ;
		if (args->philosophers->next)
			args->philosophers = args->philosophers->next;
		else
			args->philosophers = philosophers_temp;
		usleep(1000);
	}
}
