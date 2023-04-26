/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:23:15 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/26 19:46:30 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	log_taken_fork(t_philosopher *philosopher, t_simulation *simulation)
{
	pthread_mutex_lock(simulation->mutex);
	if (!simulation->is_simulation_running)
	{
		pthread_mutex_unlock(simulation->mutex);
		return ;
	}
	printf(
		"%s%ld\t %i has taken a fork%s\n",
		SHELL_BK,
		get_program_time(),
		philosopher->id,
		SHELL_RC
		);
	pthread_mutex_unlock(simulation->mutex);
}

void	log_eating(t_philosopher *philosopher, t_simulation *simulation)
{
	pthread_mutex_lock(simulation->mutex);
	if (!simulation->is_simulation_running)
	{
		pthread_mutex_unlock(simulation->mutex);
		return ;
	}
	printf(
		"%s%ld\t %i is eating%s\n",
		SHELL_G,
		get_program_time(),
		philosopher->id,
		SHELL_RC
		);
	pthread_mutex_unlock(simulation->mutex);
}

void	log_sleeping(t_philosopher *philosopher, t_simulation *simulation)
{
	pthread_mutex_lock(simulation->mutex);
	if (!simulation->is_simulation_running)
	{
		pthread_mutex_unlock(simulation->mutex);
		return ;
	}
	printf(
		"%s%ld\t %i is sleeping%s\n",
		SHELL_Y,
		get_program_time(),
		philosopher->id,
		SHELL_RC
		);
	pthread_mutex_unlock(simulation->mutex);
}

void	log_thinking(t_philosopher *philosopher, t_simulation *simulation)
{
	pthread_mutex_lock(simulation->mutex);
	if (!simulation->is_simulation_running)
	{
		pthread_mutex_unlock(simulation->mutex);
		return ;
	}
	printf(
		"%s%ld\t %i is thinking%s\n",
		SHELL_B,
		get_program_time(),
		philosopher->id,
		SHELL_RC
		);
	pthread_mutex_unlock(simulation->mutex);
}

void	log_death(t_philosopher *philosopher, t_simulation *simulation)
{
	pthread_mutex_lock(simulation->mutex);
	printf(
		"%s%ld\t %i died%s\n",
		SHELL_R,
		get_program_time(),
		philosopher->id,
		SHELL_RC
		);
	pthread_mutex_unlock(simulation->mutex);
}
