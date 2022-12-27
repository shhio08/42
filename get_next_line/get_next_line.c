/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:59:07 by stakimot          #+#    #+#             */
/*   Updated: 2022/12/27 12:04:04 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_save(int fd, char *save)
{
	char	*buff;
	int		byte;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1UL));
	if (!buff)
		return (NULL);
	while (!ft_strchr(save, '\n'))
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte <= 0)
			break ;
		buff[byte] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	buff = NULL;
	if (byte == -1)
		return (NULL);
	return (save);
}

char	*make_line(char *save, size_t cnt)
{
	char	*line;
	size_t	l_cnt;

	l_cnt = 0;
	line = (char *)malloc(sizeof(char) * cnt + 1);
	if (!line)
		return (NULL);
	while (l_cnt < cnt)
	{
		line[l_cnt] = save[l_cnt];
		l_cnt++;
	}
	line[l_cnt] = '\0';
	return (line);
}

char	*make_save(char *save, size_t cnt)
{
	char	*new_save;
	size_t	len;
	size_t	n_cnt;

	if (save[cnt] == '\n' || save[cnt] == '\0')
		return (NULL);
	len = ft_strlen(save) - cnt;
	new_save = (char *)malloc(sizeof(char) * len + 1);
	if (!new_save)
		return (NULL);
	n_cnt = 0;
	while (save[cnt])
		new_save[n_cnt++] = save[cnt++];
	new_save[n_cnt] = '\0';
	free(save);
	save = NULL;
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	size_t		cnt;

	cnt = 0;
	save = read_save(fd, save);
	if (!save)
		return (save);
	while ((save[cnt] != '\n' && save[cnt] != '\0'))
	{
		cnt++;
	}
	if (save[cnt] == '\n')
		cnt ++;
	line = make_line(save, cnt);
	save = make_save(save, cnt);
	return (line);
}

int main()
{
	int		fd;
	char	*gnl;
	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		gnl = get_next_line(fd);
		printf("%s", gnl);
		if (!gnl)
			return (0);
		free(gnl);
	}
	return (0);
}