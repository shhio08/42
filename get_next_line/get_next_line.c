/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:24:49 by stakimot          #+#    #+#             */
/*   Updated: 2022/11/30 13:14:44 by stakimot         ###   ########.fr       */
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
	save = NULL;
	if (!buff)
		return (NULL);
	while (!ft_strchr(save, '\n'))
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte <= 0)
			break;
		buff[BUFFER_SIZE] = '\0';
		save = ft_strjoin(tmp, buff);
		free(tmp);
		tmp = ft_strdup(save);
	}
	free(buff);
	buff = NULL;
	free(tmp);
	tmp = NULL;
	if (byte == -1)
		return (NULL);
	return (save);
}

char *make_line(char *buff, char *save)
{
	char	*line;
	size_t	len;
	size_t	s_len;
	size_t	cnt;
	size_t	b_cnt;

	len = 0;
	cnt = 0;
	b_cnt = 0;
	s_len = ft_strlen(save);
	while (buff[len] != '\n' && buff[len] != '\0')
		len++;
	line = (char *)malloc(sizeof(char) * (s_len + len + 2));
	if (!line)
		return (NULL);
	while (cnt < s_len)
	{
		line[cnt] = save[cnt];
		cnt++;
	}
	while (cnt < s_len + len)
		line[cnt++] = buff[b_cnt++];
	if (buff[b_cnt] == '\n')
		line[cnt++] = '\n';
	line[cnt] = '\0';
	return (line);
}

char *make_save(char *buff)
{
	size_t	len;
	size_t	b_cnt;
	size_t	s_cnt;
	char	*save;

	b_cnt = 0;
	s_cnt = 0;
	while (buff[b_cnt] != '\n' && buff[b_cnt] != '\0')
		b_cnt++;
	if (buff[b_cnt] == '\n')
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
	char		*buff;
	static char	*save;
	char		*line;

	buff = read_buff(fd);
	if (!buff)
		return (NULL);
	line = make_line(buff, save);
	printf("a:%s", line);
	if (!line)
		return (NULL);
	save = make_save(buff);
	if (!save)
		return (NULL);
	free(buff);
	buff = NULL;
	return (line);
}

#include <stdlib.h>

int	main()
{
	int fd;
	char *gnl;
	int i=0;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		gnl = get_next_line(fd);
		printf("%d:%s",i++ , gnl);
		if (!gnl)
			return (0);
	}
	// gnl = get_next_line(fd);
	// printf("%s", gnl);
	system("leaks a.out");
	return(0);
}