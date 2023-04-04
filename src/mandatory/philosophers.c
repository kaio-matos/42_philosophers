/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:38:23 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/03 21:12:15 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	philosophers(
	int number_of_philosophers,
	int time_to_die,
	int time_to_eat,
	int time_to_sleep,
	int number_of_times_each_philosopher_must_eat
)
{
	printf("number_of_philosophers: %i\n", number_of_philosophers);
	printf("time_to_die: %i\n", time_to_die);
	printf("time_to_eat: %i\n", time_to_eat);
	printf("time_to_sleep: %i\n", time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat: %i\n", number_of_times_each_philosopher_must_eat);
}
