/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:59:07 by stakimot          #+#    #+#             */
/*   Updated: 2023/01/07 20:57:47 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_free(char *s)
{
	free(s);
	s = NULL;
	return (NULL);
}

char	*read_save(int fd, char *save)
{
	char	*buff;
	char	*tmp;
	int		byte;

	tmp = NULL;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1UL));
	if (!buff)
		return (NULL);
	while (!ft_strchr(save, '\n'))
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte <= 0)
			break ;
		buff[byte] = '\0';
		tmp = ft_strjoin(save, buff);
		free(save);
		save = tmp;
	}
	get_free(buff);
	if (byte == -1)
		return (NULL);
	return (save);
}

char	*make_line(char *save, size_t cnt)
{
	char	*line;
	size_t	l_cnt;

	l_cnt = 0;
	line = (char *)malloc(sizeof(char) * (cnt + 1));
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

	if (save[cnt] == '\0')
	{
		get_free(save);
		return (NULL);
	}
	len = ft_strlen(save) - cnt;
	new_save = (char *)malloc(sizeof(char) * len + 1);
	if (!new_save)
		return (NULL);
	n_cnt = 0;
	while (save[cnt])
		new_save[n_cnt++] = save[cnt++];
	new_save[n_cnt] = '\0';
	get_free(save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*line;
	size_t		cnt;

	cnt = 0;
	save[fd] = read_save(fd, save[fd]);
	if (!save[fd])
		return (save[fd]);
	while ((save[fd][cnt] != '\n' && save[fd][cnt] != '\0'))
	{
		cnt++;
	}
	if (save[fd][cnt] == '\n')
		cnt ++;
	line = make_line(save[fd], cnt);
	save[fd] = make_save(save[fd], cnt);
	return (line);
}

#include<fcntl.h>
int main(int argc, char const *argv[])
{
	int		fd;
	int		fd1;
	char	*gnl;
	char	*gnl1;

	fd = open("test.txt", O_RDONLY);
	fd1 = open("test1.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	// system("leaks a.out");
	return (0);
}
