/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:19:23 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/03 21:24:08 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	ft_isstrdigit(char *s)
{
	while (s && *s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}
