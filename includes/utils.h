/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:19:22 by celadia           #+#    #+#             */
/*   Updated: 2022/04/22 11:20:56 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define KEY_PRESS 2
# define DESTROY 17

void	ft_error(void);
int		ft_strlen(const char *str);
void	ft_message(const char *str, char *color);
void	terminate(const char *str, void *address);
void	*mem_alloc(size_t size);

#endif //UTILS_H
