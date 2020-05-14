/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurad <smurad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 04:19:49 by smurad            #+#    #+#             */
/*   Updated: 2020/05/14 05:35:04 by smurad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del_first_char(char *str)
{
	int i;

	i = 1;
	while (str[i])
	{
		str[i - 1] = str[i];
		i++;
	}
	str[i - 1] = str[i];
}

char	*append_char(char *str, char chr)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = chr;
	res[i + 1] = '\0';
	return (res);
}

int		buffer_to_line(char *buffer, char **line)
{
	char *no_leaks;

	no_leaks = NULL;
	while (buffer[0])
	{
		if (buffer[0] == '\n')
		{
			del_first_char(buffer);
			return (1);
		}
		else
		{
			no_leaks = ft_strdup(*line);
			free(*line);
			*line = append_char(no_leaks, buffer[0]);
			free(no_leaks);
			del_first_char(buffer);
		}
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			res_read;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	*line = ft_strdup("");
	if (buffer_to_line(buffer, line))
		return (1);
	while ((res_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[res_read] = '\0';
		if (buffer_to_line(buffer, line))
			return (1);
	}
	return (res_read);
}
