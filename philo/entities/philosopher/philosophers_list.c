/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:32:36 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/06 20:08:49 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_list	*create_philosophers(
	int amount,
	void *(*routine)(void *)
)
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
		ft_lstadd_back(&philosophers, ft_lstnew(create_philosopher(i + 1, forks, routine)));
		i++;
	}
	return (philosophers);
}

void	free_philosophers(t_list **philosophers)
{
	ft_lstclear(philosophers, &free);
	free(*philosophers);
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
