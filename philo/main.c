/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:42:25 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/03 21:06:06 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	main(int argc, char **argv)
{
	t_arguments	args;

	if (v__arguments(argc, argv))
		return (1);
	args = p__arguments(argc, argv);
	philosophers(
		args.number_of_philosophers,
		args.time_to_die,
		args.time_to_eat,
		args.time_to_sleep,
		args.number_of_times_each_philosopher_must_eat
	);
	return (0);
}
