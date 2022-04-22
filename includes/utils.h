#ifndef UTILS_H
# define UTILS_H

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define MOUSE_PRESS 4
# define MOUSE_RELEASE 5
# define DESTROY 17

void	ft_error(void);
int		ft_strlen(const char *str);
void	ft_message(const char *str, char *color);
void	terminate(const char *str, void *address);
void	*mem_alloc(size_t size);


#endif //UTILS_H
