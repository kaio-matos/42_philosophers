/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:23:15 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/06 21:16:30 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	log_taken_fork(t_philosopher *philosopher)
{
	printf("%ld\t %i has taken a fork\n",	get_program_time(), philosopher->id);
}

void	log_eating(t_philosopher *philosopher)
{
	printf("%ld\t %i is eating\n", get_program_time(), philosopher->id);
}

void	log_sleeping(t_philosopher *philosopher)
{
	printf("%ld\t %i is sleeping\n", get_program_time(), philosopher->id);
}

void	log_thinking(t_philosopher *philosopher)
{
	printf("%ld\t %i is thinking\n", get_program_time(), philosopher->id);
}
