/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   th__observer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:38:57 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/18 21:38:21 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*th_observer_routine(void	*args_void)
{
	t_observer_routine	*args;
	t_list				*philosophers_temp;

	args = args_void;
	philosophers_temp = args->philosophers;
	if (!philosophers_temp->next)
	{
		free(args_void);
		log_death(get_philosopher(args->philosophers));
		return (NULL);
	}
	while (TRUE)
	{
		if (are_philosophers_satisfied(philosophers_temp))
			break ;
		if (is_philosopher_dead(get_philosopher(args->philosophers)))
		{
			*args->is_simulation_running = FALSE;
			break ;
		}
		if (args->philosophers->next)
			args->philosophers = args->philosophers->next;
		else
			args->philosophers = philosophers_temp;
	}
	free(args_void);
	return (NULL);
}

void	th__create_observer(t_list *philosophers, int *is_simulation_running, pthread_t	*thread)
{
	t_observer_routine	*observer_routine_args;

	observer_routine_args = ft_salloc(sizeof(t_observer_routine));
	observer_routine_args->philosophers = philosophers;
	observer_routine_args->is_simulation_running = is_simulation_running;
	if (pthread_create(thread, NULL, th_observer_routine, observer_routine_args))
	{
		free(observer_routine_args);
		printf("Error creating thread\n"); // TODO
	}
}
