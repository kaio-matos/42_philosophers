/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p__arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:41:30 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/03 21:14:23 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_arguments	p__arguments(int argc, char **argv)
{
	t_arguments	args;

	args.number_of_philosophers = ft_atoi(argv[1]);
	args.time_to_die = ft_atoi(argv[2]);
	args.time_to_eat = ft_atoi(argv[3]);
	args.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		args.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		args.number_of_times_each_philosopher_must_eat = -1;
	return (args);
}
