/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:17:30 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/06 21:18:31 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static long int	seconds_to_ms(long int seconds);
static long int	microseconds_to_ms(long int microseconds);

long int	get_program_time(void)
{
	static struct timeval	program_started_at;
	static int				has_saved;
	struct timeval			current_time;
	long int				current_ms;
	long int				started_at_ms;

	if (!has_saved)
	{
		if (gettimeofday(&program_started_at, NULL) == -1)
			printf("Error"); //TODO
		has_saved = 1;
		return (0);
	}
	if (gettimeofday(&current_time, NULL) == -1)
		printf("Error"); //TODO
	current_ms = seconds_to_ms(current_time.tv_sec) + microseconds_to_ms(current_time.tv_usec);
	started_at_ms = seconds_to_ms(program_started_at.tv_sec) + microseconds_to_ms(program_started_at.tv_usec);
	return (current_ms - started_at_ms);
}

static long int	seconds_to_ms(long int seconds)
{
	return (seconds * MILISECOND);
}

static long int	microseconds_to_ms(long int microseconds)
{
	return (microseconds / MILISECOND);
}
