/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:25:40 by celadia           #+#    #+#             */
/*   Updated: 2022/04/22 09:10:10 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

#define CHAR_SIZE 5

void	print_map_error(t_merr *err)
{
	if (err->rowlen)
		terminate(ERR_MAP_R, NULL);
	if (err->borders)
		terminate(ERR_MAP_W, NULL);
	if (err->n_players)
		terminate(ERR_MAP_P, NULL);
	if (err->n_collect)
		terminate(ERR_MAP_C, NULL);
	if (err->n_exits)
		terminate(ERR_MAP_E, NULL);
}

void	check_line(char *line, t_mchk *op, t_merr *err)
{
	if ((line[op->col - 1] == '\n' && ft_strlen(line) != op->col) || \
		(line[op->col - 1] == '\0' && ft_strlen(line) != op->col - 1))
		err->rowlen = 1;
	if ((op->fl_line && op->char_arr[WALL_INDEX] != op->col - 1) || \
		(line[0] != '1' && line[op->col - 2] != '1'))
		err->borders = 1;
	err->n_collect = op->char_arr[COL_INDEX] < 1;
	err->n_exits = op->char_arr[EXIT_INDEX_CL] != 1;
	err->n_players = op->char_arr[PLAYER_INDEX] != 1;
}

void	map_opt_fill(char *line, t_mchk *op, t_game *game)
{
	int		index;
	int		i;

	i = 0;
	op->fl_line = 0;
	if (op->row == 1 || line[op->col - 1] != '\n')
		op->fl_line = 1;
	op->char_arr[EMPTY_INDEX] = 0;
	op->char_arr[WALL_INDEX] = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		index = (int)((line[i] - 47 + (line[i] / 69)) % 10);
		if (index >= CHAR_SIZE)
			terminate(ERR_MAP_S, line);
		if (index == PLAYER_INDEX || index == EXIT_INDEX_CL)
			pos_init(game, i, op->row - 1, index);
		op->char_arr[index]++;
		i++;
	}
}

void	read_col_row(int fd, t_mchk *op, t_merr *err, t_game *game)
{
	char	*line;

	op->row = 0;
	line = get_next_line(fd, BUFF_SIZE);
	op->col = ft_strlen(line);
	while (line && ++op->row)
	{
		map_opt_fill(line, op, game);
		check_line(line, op, err);
		free(line);
		line = get_next_line(fd, op->col);
	}
	close(fd);
}

void	check_map(int fd, t_game *game)
{
	t_merr	err;
	t_mchk	opt;

	map_opt_init(&opt);
	map_err_init(&err);
	read_col_row(fd, &opt, &err, game);
	print_map_error(&err);
	game->map->col = opt.col;
	game->map->row = opt.row;
	game->player->collect = opt.char_arr[COL_INDEX];
}
