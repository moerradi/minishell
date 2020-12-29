/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:48:58 by moerradi          #+#    #+#             */
/*   Updated: 2020/12/29 16:03:44 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//this is basically get_net_line that doesn't give a fuck about 
//the read return of 0 (eof) in order to replicate the ctrl+D bash behaviour
//it is pretty decent but needs some editing to replicate some wierd behaviours like
//ctrl+C then ctrl+D that should exit the terminal normally


static char	*free_ptr(char **buffer)
{
	char *buff;

	buff = *buffer;
	free(buff);
	return (NULL);
}

static char	*buffered_read(const int fd, char *rest)
{
	int		read_ret;
	char	*temp;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 1 || !(buffer = malloc(sizeof(char) * \
		(BUFFER_SIZE + 1))) || read(fd, buffer, 0) < 0)
		return (NULL);
	while (!ft_strchr_s(rest, '\n'))
	{
		temp = rest;
		if ((read_ret = read(fd, buffer, BUFFER_SIZE)) < 0)
			return (free_ptr(&buffer));
		buffer[read_ret] = '\0';
		rest = ft_strjoin(rest, buffer);
		free(temp);
		if (*rest == '\0')
			break ;
	}
	free(buffer);
	return (rest);
}

int		get_cmd_line(int fd, char **line)
{
	char			*temp;
	static char		*rest[ULILMIT];
	int				newline_pos;

	if (!(rest[fd] = buffered_read(fd, rest[fd])))
		return (-1);
	if (((temp = ft_strchr_s(rest[fd], '\n'))))
	{
		newline_pos = temp - rest[fd];
		temp = ft_strdup(temp + 1);
		if (!temp || !(*line = ft_strndup(rest[fd], newline_pos)))
			return (-1);
		free(rest[fd]);
		rest[fd] = ft_strdup(temp);
		free(temp);
		return (1);
	}
	else
	{
		if ((*line = ft_strdup(rest[fd])) == NULL)
			return (-1);
		free(rest[fd]);
		rest[fd] = NULL;
		return (0);
	}
}