/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:18:08 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/05/05 21:12:01 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_philosopher	*create_philosopher(int id, t_arguments args)
{
	t_philosopher	*philosopher;

	philosopher = ft_salloc(sizeof(t_philosopher));
	philosopher->id = id;
	philosopher->mutex = ft_salloc(sizeof(pthread_mutex_t));
	philosopher->time_to_die = args.time_to_die;
	philosopher->time_to_eat = args.time_to_eat;
	philosopher->time_to_sleep = args.time_to_sleep;
	philosopher->times_to_eat = args.number_of_times_each_philosopher_must_eat;
	philosopher->times_eaten = 0;
	philosopher->last_meal_ms = -1;
	pthread_mutex_init(philosopher->mutex, NULL);
	return (philosopher);
}

int	is_philosopher_dead(t_philosopher *philosopher, t_simulation *simulation)
{
	int	result;

	result = FALSE;
	pthread_mutex_lock(philosopher->mutex);
	if (philosopher->last_meal_ms == -1)
		result = FALSE;
	else if (philosopher->times_eaten == philosopher->times_to_eat)
		result = FALSE;
	else if (
		get_time_offset_ms(philosopher->last_meal_ms) > philosopher->time_to_die
	)
	{
		simulation->is_simulation_running = FALSE;
		usleep(1000);
		log_death(philosopher, simulation);
		result = TRUE;
	}
	pthread_mutex_unlock(philosopher->mutex);
	return (result);
}

void	update_philosopher_last_meal(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->mutex);
	philosopher->last_meal_ms = current_time_ms();
	pthread_mutex_unlock(philosopher->mutex);
}

t_philosopher	*get_philosopher(t_list *node)
{
	return ((t_philosopher *)node->content);
}
