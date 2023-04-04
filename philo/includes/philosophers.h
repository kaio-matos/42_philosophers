/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:06:58 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/04 20:02:39 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>

/**
 * Arguments
 * number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
 *
 * ◦ number_of_philosophers:
 * 		The number of philosophers and also the number of forks.
 *
 * ◦ time_to_die (in milliseconds):
 * 		If a philosopher didn’t start eating time_to_die milliseconds since
 * 		the beginning of their last meal or the beginning of the simulation, they die.
 *
 * ◦ time_to_eat (in milliseconds):
 * 		The time it takes for a philosopher to eat.
 * 		During that time, they will need to hold two forks.
 *
 * ◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
 *
 * ◦ number_of_times_each_philosopher_must_eat (optional argument):
 * 		If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times,
 * 		the simulation stops. If not specified, the simulation stops when a philosopher dies.
*/

/**
 * Allowed functions
 *
 * memset, printf, malloc, free, write,
 * usleep, gettimeofday, pthread_create,
 * pthread_detach, pthread_join, pthread_mutex_init,
 * pthread_mutex_destroy, pthread_mutex_lock,
 * pthread_mutex_unlock
*/

typedef struct s_arguments
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_arguments;

typedef struct s_forks
{
	int	left;
	int	right;
}	t_forks;

typedef struct s_philosopher
{
	int		id;
	t_forks	forks;
}	t_philosopher;

typedef struct s_philosophers
{
	t_arguments	args;
}	t_philosophers;

/**
 * @param number_of_philosophers The number of philosophers and also the number of forks.
 * @param time_to_die If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
 * @param time_to_eat The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
 * @param time_to_sleep The time a philosopher will spend sleeping.
 * @param number_of_times_each_philosopher_must_eat (OPTIONAL) If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
*/
void		philosophers(
					int number_of_philosophers,
					int time_to_die,
					int time_to_eat,
					int time_to_sleep,
					int number_of_times_each_philosopher_must_eat
				);

/******************************************************************************\
* VALIDATION																   *
\******************************************************************************/

int			v__arguments(int argc, char **argv);


/******************************************************************************\
* PARSER																	   *
\******************************************************************************/

t_arguments	p__arguments(int argc, char **argv);


/******************************************************************************\
* UTILS																		   *
\******************************************************************************/

int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);
int			ft_isstrdigit(char *s);

#endif
