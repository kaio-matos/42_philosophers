/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v__arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:39:44 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/03 21:31:14 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	is_valid(char *arg, char *name)
{
	if (!arg)
	{
		printf("Error: missing `%s` argument\n", name);
		return (0);
	}
	if (!ft_isstrdigit(arg))
	{
		printf("Error: invalid `%s` argument\n", name);
		return (0);
	}
	return (1);
}

int	v__arguments(int argc, char **argv)
{
	if (!is_valid(argv[1], "number_of_philosophers"))
		return (1);
	if (!is_valid(argv[2], "time_to_die"))
		return (1);
	if (!is_valid(argv[3], "time_to_eat"))
		return (1);
	if (!is_valid(argv[4], "time_to_sleep"))
		return (1);
	if (argv[5] && !ft_isstrdigit(argv[5]))
		return (printf("Error: invalid `number_of_times_each_philosopher_must_eat` argument\n"));
	return (0);
}
