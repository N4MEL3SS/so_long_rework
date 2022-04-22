/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:27:01 by celadia           #+#    #+#             */
/*   Updated: 2022/04/20 12:43:50 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	terminate(const char *str, void *address)
{
	free(address);
	address = NULL;
	ft_error();
	ft_message(str, GREEN);
	exit(EXIT_FAILURE);
}

void	*mem_alloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		terminate(ERR_MALLOC, ptr);
	return (ptr);
}
