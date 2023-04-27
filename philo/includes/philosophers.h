/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:06:58 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/26 21:17:01 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <headers.h>
# include <linked_list.h>

# define MICROSECOND 1
# define MILISECOND 1000
# define TRUE 1
# define FALSE 0

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

typedef struct s_simulation
{
	int				is_simulation_running;
	pthread_mutex_t	*mutex;
}	t_simulation;

typedef struct s_fork
{
	int				id;
	int				philosopher_id;
	pthread_mutex_t	*mutex;
}	t_fork;

typedef struct s_philosopher
{
	int			id;
	pthread_t	thread;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			times_to_eat;
	int			times_eaten;
	long		last_meal_ms;
}	t_philosopher;

typedef struct s_using_forks
{
	t_fork		*mine;
	t_fork		*borrowed;
}	t_using_forks;

typedef struct s_philosopher_routine
{
	t_philosopher	*philosopher;
	t_dlist			*forks;
	t_simulation	*simulation;
}	t_philosopher_routine;

typedef struct s_observer_routine
{
	t_list			*philosophers;
	t_simulation	*simulation;
}	t_observer_routine;

/**
 * @param number_of_philosophers The number of philosophers and also
 * 			the number of forks.
 * @param time_to_die If a philosopher didn’t start eating time_to_die
 * 			milliseconds since the beginning of their last meal or the
 * 			beginning of the simulation, they die.
 * @param time_to_eat The time it takes for a philosopher to eat.
 * 			During that time, they will need to hold two forks.
 * @param time_to_sleep The time a philosopher will spend sleeping.
 * @param number_of_times_each_philosopher_must_eat (OPTIONAL) If all
 * 			philosophers have eaten at least
 * 			number_of_times_each_philosopher_must_eat times, the simulation
 * 			stops. If not specified, the simulation stops when
 * 			a philosopher dies.
*/
void			philosophers(t_arguments args);

/******************************************************************************\
* VALIDATION																   *
\******************************************************************************/

int				v__arguments(int argc, char **argv);

/******************************************************************************\
* PARSER																	   *
\******************************************************************************/

t_arguments		p__arguments(int argc, char **argv);

/******************************************************************************\
* UTILS																		   *
\******************************************************************************/

int				ft_atoi(const char *nptr);
int				ft_isdigit(int c);
int				ft_isstrdigit(char *s);
void			*ft_salloc(size_t size);

/******************************************************************************\
* ENTITIES																	   *
\******************************************************************************/

/**
 * PHILOSOPHER
*/
t_philosopher	*create_philosopher(int id, t_arguments args);
t_philosopher	*get_philosopher(t_list *node);
t_list			*create_philosophers(t_arguments args);
void			free_philosophers(t_list **philosophers);
void			wait_philosophers(t_list *philosophers);
int				is_philosopher_dead(
					t_philosopher *philosopher,
					t_simulation *simulation
					);
int				are_philosophers_satisfied(t_list *philosophers);

/**
 * FORK
*/
t_fork			*create_fork(int id, int philosopher_id);
t_fork			*get_fork(t_dlist *node);
t_dlist			*create_forks(int number_of_forks);
void			free_forks(t_dlist **forks);
void			print_forks(t_dlist *forks);
void			print_fork(t_fork *fork);
t_dlist			*find_fork_node_by_philosopher_id(
					t_dlist *forks,
					int philosopher_id
					);

/**
 * SIMULATION
*/
t_simulation	*create_simulation(void);
void			free_simulation(t_simulation *simulation);

/******************************************************************************\
* THREADS																	   *
\******************************************************************************/

void			th__create_observer(
					t_list *philosophers,
					t_simulation *simulation,
					pthread_t *thread
					);
void			*th_philosopher_routine(void *args_void);
void			th__create_philosophers_threads(
					t_list *philosophers,
					t_dlist *forks,
					t_simulation *simulation,
					void *(*philosopher_routine)(void *)
					);

/******************************************************************************\
* TIME																		   *
\******************************************************************************/

long int		get_program_time(void);
long int		current_time_ms(void);
long int		get_time_offset_ms(long started_time);
void			mssleep(size_t ms_time);
void			mssleep_checking_death(
					t_philosopher_routine *args,
					size_t ms_time
					);

/******************************************************************************\
* LOG																		   *
\******************************************************************************/

void			log_taken_fork(
					t_philosopher *philosopher,
					t_simulation *simulation
					);
void			log_eating(
					t_philosopher *philosopher,
					t_simulation *simulation
					);
void			log_sleeping(
					t_philosopher *philosopher,
					t_simulation *simulation
					);
void			log_thinking(
					t_philosopher *philosopher,
					t_simulation *simulation
					);
void			log_death(
					t_philosopher *philosopher,
					t_simulation *simulation
					);

/******************************************************************************\
* ACTIONS																	   *
\******************************************************************************/

void			a__eat(t_philosopher_routine *args);
void			a__sleep(t_philosopher_routine *args);
t_using_forks	*a__take_fork(t_philosopher_routine *args, t_dlist *fork_node);
void			a__put_forks_on_table(t_using_forks *using_forks);
void			a__think(t_philosopher_routine *args);

#endif
