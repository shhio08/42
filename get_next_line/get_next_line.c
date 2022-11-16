/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:24:49 by stakimot          #+#    #+#             */
/*   Updated: 2022/11/16 15:33:42 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_buff(int fd)
{
	char	*buff;
	char	*save;
	char	*tmp;
	int		byte;

	tmp = NULL;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(save, '\n'))
	{
		byte = read(fd, buff, 4);
		if (byte == -1)
			return (NULL);
		save = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + BUFFER_SIZE + 1));
		if (!save)
			return (NULL);
		save = ft_strjoin(tmp, buff);
		tmp = (char *)malloc(sizeof(char) * (ft_strlen(save) + 1));
		tmp = save;
	}
	return (save);
}

char *make_line(char *buff, char *save)
{
	char	*line;
	int		len;
	int		s_len;
	int		cnt;
	int		b_cnt;

	len = 0;
	cnt = 0;
	b_cnt = 0;
	s_len = ft_strlen(save);
	while (buff[len] != '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (s_len + len + 1));
	if (!line)
		return (NULL);
	while (cnt < s_len)
	{
		line[cnt] = save[cnt];
		cnt++;
	}
	while (cnt < s_len + len)
		line[cnt++] = buff[b_cnt++];
	line[cnt] = '\n';
	return (line);
}
char *make_save(char *buff)
{
	int		len;
	int		b_cnt;
	int		s_cnt;
	char	*save;

	b_cnt = 0;
	s_cnt = 0;
	while (buff[b_cnt] != '\n')
		b_cnt++;
	len = ft_strlen(buff) - b_cnt;
	save = (char *)malloc(sizeof(char) * len + 1);
	if (!save)
		return (NULL);
	while (s_cnt < len)
		save[s_cnt++] = buff[b_cnt++];
	save[s_cnt] = '\0';
	return (save);
}

char	*get_next_line(int fd)
{
	char	*buff;
	static char	*save;
	char	*line;
	int		cnt;

	buff = read_buff(fd);
	if (!buff)
		return (NULL);
	line = make_line(buff, save);
	if (!line)
		return (NULL);
	save = make_save(buff);
	if (!save)
		return (NULL);
	return (line);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int	main()
{
	int fd;
	char *gnl;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		gnl = get_next_line(fd);
		if (!gnl)
			return (0);
		printf("%s", gnl);
	}
	return(0);
}