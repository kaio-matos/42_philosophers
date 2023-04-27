/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:32:36 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/26 20:55:07 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_list	*create_philosophers(t_arguments args)
{
	int		i;
	t_list	*philosophers;

	i = 0;
	philosophers = NULL;
	while (i < args.number_of_philosophers)
	{
		ft_lstadd_back(&philosophers, ft_lstnew(create_philosopher(
			i + 1,
			args
		)));
		i++;
	}
	return (philosophers);
}

void	free_philosophers(t_list **philosophers)
{
	ft_lstclear(philosophers, &free);
	free(*philosophers);
}

int	are_philosophers_satisfied(t_list *philosophers)
{
	while (philosophers)
	{
		if (get_philosopher(philosophers)->times_eaten != get_philosopher(philosophers)->times_to_eat)
			return (FALSE);
		philosophers = philosophers->next;
	}
	return (TRUE);
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
