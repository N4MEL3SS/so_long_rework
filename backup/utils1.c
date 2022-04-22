/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:26:56 by celadia           #+#    #+#             */
/*   Updated: 2022/04/20 12:26:56 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str && ++len)
		str++;
	return (len);
}

void	ft_error(void)
{
	write(1, RED, COLOR_SIZE);
	write(1, "Error!", 5);
	write(1, COLOR_END, COLOR_SIZE);
	write(1, "\n", 1);
}

void	ft_message(const char *str, char *color)
{
	write(1, color, COLOR_SIZE);
	write(1, str, ft_strlen(str));
	write(1, COLOR_END, COLOR_SIZE);
	write(1, "\n", 1);
}
