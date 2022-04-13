#ifndef GAME_H
# define GAME_H

# include <stdlib.h> /* malloc, free, exit */
# include <stdio.h> /* perror, strerror */
# include <fcntl.h> /* open */
# include <unistd.h> /* read, write, close */

# include "mlx.h"
# include "error_msg.h"

int	check_arg(int argc, char **map);

void	ft_error(void);
size_t	ft_strlen(const char *str);
void	ft_putendl(const char *str);
void	terminate(const char *str, void *address);

#endif //GAME_H
