/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:59:22 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/21 20:18:22 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_exterr(char *message, ...)
{
	va_list	args;

	va_start(args, message);
	ft_vprterr(message, args);
	va_end(args);
	exit(EXIT_FAILURE);
}

void	ft_exterra(int errno, char *message, ...)
{
	va_list	args;

	va_start(args, message);
	ft_vprterr(message, args);
	va_end(args);
	exit(errno);
}
