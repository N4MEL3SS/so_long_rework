#ifndef GAME_H
# define GAME_H

# include <stdlib.h> /* malloc, free, exit */
# include <stdio.h> /* perror, strerror */
# include <fcntl.h> /* open */
# include <unistd.h> /* read, write, close */

# include "mlx.h"
# include "map.h"
# include "keycode_mac.h"
# include "utils.h"
# include "error_msg.h"

# define B_SIZE 32

char	*get_next_line(int fd, int buff_size);

void	ft_error(void);
size_t	ft_strlen(const char *str);
void	ft_message(const char *str);
void	ft_warning(const char *str);
void	terminate(const char *str, void *address);
void	*mem_alloc(size_t size);

#endif //GAME_H
