/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_salloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 02:51:25 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/04 21:35:56 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*ft_salloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem && size > 0)
	{
		printf("MEMORY ALLOCATION ERROR"); // TODO
		exit(EXIT_FAILURE);
	}
	return (mem);
}
