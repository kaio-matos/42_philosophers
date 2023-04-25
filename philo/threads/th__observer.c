/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   th__observer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:38:57 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/25 02:28:29 by kmatos-s         ###   ########.fr       */
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
		log_death(get_philosopher(args->philosophers), args->simulation);
		return (NULL);
	}
	while (TRUE)
	{
		if (are_philosophers_satisfied(philosophers_temp))
			break ;
		if (is_philosopher_dead(get_philosopher(args->philosophers), args->simulation))
			break ;
		if (args->philosophers->next)
			args->philosophers = args->philosophers->next;
		else
			args->philosophers = philosophers_temp;
		usleep(3000);
	}
	free(args_void);
	return (NULL);
}

void	th__create_observer(t_list *philosophers, t_simulation *simulation, pthread_t	*thread)
{
	t_observer_routine	*observer_routine_args;

	observer_routine_args = ft_salloc(sizeof(t_observer_routine));
	observer_routine_args->philosophers = philosophers;
	observer_routine_args->simulation = simulation;
	if (pthread_create(thread, NULL, th_observer_routine, observer_routine_args))
	{
		free(observer_routine_args);
		printf("Error creating thread\n"); // TODO
	}
}
