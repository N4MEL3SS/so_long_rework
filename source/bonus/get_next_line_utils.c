/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:26:04 by celadia           #+#    #+#             */
/*   Updated: 2022/04/20 12:26:04 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buff_str_init(int buff_size)
{
	char	*buff_str;

	buff_str = malloc(sizeof(char) * ((ssize_t)buff_size + 1));
	if (!buff_str)
		return (NULL);
	*buff_str = '\0';
	return (buff_str);
}

void	*ft_free_ptr(void *ptr)
{
	free(ptr);
	ptr = NULL;
	return (NULL);
}

void	ft_str_cpy(char *str, ssize_t line_len)
{
	char		*shift;

	shift = str + line_len;
	while (*shift)
		*(str++) = *(shift++);
	*str = '\0';
}

int	ft_str_chr(char *str, ssize_t *len)
{
	*len = 0;
	while (*str && *str != '\n' && ++*len)
		str++;
	if (*str == '\n' && ++*len)
		return (1);
	return (0);
}

char	*ft_str_join(char *dst, char *src, ssize_t line_len)
{
	char	*temp_join;
	char	*temp_dst;
	char	*join;

	if (*src == '\0')
		return (dst);
	line_len++;
	join = malloc(sizeof(char) * (line_len));
	if (!join)
		return (NULL);
	temp_join = join;
	temp_dst = dst;
	while (*dst && --line_len)
		*(join++) = *(dst++);
	while (*src && --line_len)
		*(join++) = *(src++);
	*join = '\0';
	free(temp_dst);
	return (temp_join);
}
