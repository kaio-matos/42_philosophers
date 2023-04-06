/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:38:23 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/05 21:15:51 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*routine(void	*philosopher_void)
{
	t_philosopher	*philosopher;

	philosopher = philosopher_void;
	// printf("id: %i\n", philosopher->id);
}

t_philosopher	*create_philosopher(int id, t_forks forks)
{
	t_philosopher	*philosopher;

	philosopher = ft_salloc(sizeof(t_philosopher));
	philosopher->id = id;
	philosopher->forks = forks;
	if (pthread_create(&philosopher->thread, NULL, &routine, philosopher)) {
		printf("Error creating thread\n"); // TODO
	}
	return (philosopher);
}

t_list	*create_philosophers(int amount)
{
	int		i;
	t_list	*philosophers;
	t_forks	forks;

	i = 0;
	philosophers = NULL;
	while (i < amount)
	{
		forks.left = 0;
		forks.right = 1;
		ft_lstadd_back(&philosophers, ft_lstnew(create_philosopher(i, forks)));
		i++;
	}
	return (philosophers);
}

void	wait_philosophers(t_list *philosophers)
{
	while (philosophers)
	{
		if (pthread_join(get_philosopher(philosophers)->thread, NULL))
			printf("Error waiting thread\n"); // TODO
		philosophers = philosophers->next;
	}
}

void	free_philosophers(t_list **philosophers)
{
	ft_lstclear(philosophers, &free);
	free(*philosophers);
}

t_fork	*create_fork(int id, int philosopher_id)
{
	t_fork	*fork;

	fork = ft_salloc(sizeof(t_fork));
	fork->id = id;
	fork->philosopher_id = philosopher_id;
	return (fork);
}

t_list	*create_forks(int number_of_forks)
{
	int		i;
	t_list	*forks;

	i = 0;
	forks = NULL;
	while (i < number_of_forks)
	{
		ft_lstadd_back(&forks, ft_lstnew(create_fork(i, -1)));
		i++;
	}
	return (forks);
}

t_fork	*get_fork(t_list *node)
{
	return ((t_fork *)node->content);
}

void	print_forks(t_list *forks)
{
	while (forks)
	{
		printf("\nfork {\n");
		printf("   id			%i\n", get_fork(forks)->id);
		printf("   philsopher_id	%i\n", get_fork(forks)->philosopher_id);
		printf("}\n\n");
		forks = forks->next;
	}
}

void	free_forks(t_list **forks)
{
	ft_lstclear(forks, &free);
	free(*forks);
}

void	attach_forks_to_philosophers(t_list	*forks, t_list *philosophers)
{
	while (philosophers)
	{
		get_fork(forks)->philosopher_id = get_philosopher(philosophers)->id;
		forks = forks->next;
		philosophers = philosophers->next;
	}
}

void	philosophers(
	int number_of_philosophers,
	int time_to_die,
	int time_to_eat,
	int time_to_sleep,
	int number_of_times_each_philosopher_must_eat
)
{
	t_list	*philosophers;
	t_list	*forks;

	philosophers = create_philosophers(number_of_philosophers);
	forks = create_forks(number_of_philosophers);
	attach_forks_to_philosophers(forks, philosophers);
	print_forks(forks);
	free_forks(&forks);
	wait_philosophers(philosophers);
	free_philosophers(&philosophers);
}
