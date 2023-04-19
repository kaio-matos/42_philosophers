/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mssleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:05:13 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/18 21:22:01 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	mssleep(size_t ms_time)
{
	size_t	start;

	start = current_time_ms();
	while (ms_time > current_time_ms() - start)
		usleep(100);
}

void	mssleep_checking_death(t_philosopher_routine *args, size_t ms_time)
{
	size_t	start;

	start = current_time_ms();
	while (ms_time > current_time_ms() - start && *args->is_simulation_running)
		usleep(100);
}
