/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:16:52 by celadia           #+#    #+#             */
/*   Updated: 2022/04/22 11:16:52 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_move_msg(char *str, int n, t_game *game)
{
	char	msg[4];
	int		i;

	i = -1;
	msg[++i] = (char)(n / 100 + 48);
	msg[++i] = (char)(n % 100 / 10 + 48);
	msg[++i] = (char)(n % 10 + 48);
	msg[++i] = '\0';
	(void)game;
	write(1, BLUE, COLOR_SIZE);
	write(1, str, ft_strlen(str));
	write(1, msg, ft_strlen(msg));
	write(1, COLOR_END, COLOR_SIZE);
	write(1, "\n", 1);
}
