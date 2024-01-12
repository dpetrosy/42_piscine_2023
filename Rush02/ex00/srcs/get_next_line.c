/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:51:26 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/29 14:58:21 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*ret_line;
	int			i;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = get_joined_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		++i;
	if (buffer[i] == '\n')
		++i;
	ret_line = ft_substr(buffer, 0, i);
	temp = ft_substr(buffer, i, ft_strlen(buffer) - (i));
	free(buffer);
	buffer = temp;
	return (ret_line);
}

char	*get_joined_buffer(char *buffer, int fd)
{
	char	temp[BUFFER_SIZE + 1];
	int		i;

	temp[BUFFER_SIZE] = '\0';
	i = -1;
	while (++i < BUFFER_SIZE)
		temp[i] = '\0';
	i = 1;
	while (!ft_strchr(temp, '\n') && i != 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i < 0 || (i == 0 && !buffer))
			return (NULL);
		temp[i] = '\0';
		if (!buffer)
			buffer = ft_strdup(temp);
		else
			buffer = ft_strjoin(buffer, temp);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
}
