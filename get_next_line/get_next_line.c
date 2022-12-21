/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:24:49 by stakimot          #+#    #+#             */
/*   Updated: 2022/12/21 02:33:01 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char		buff;
	static char	save;
	char		line;
	
}

#include <stdlib.h>

int	main()
{
	int fd;
	char *gnl;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		gnl = get_next_line(fd);
		printf("%s", gnl);
		if (!gnl)
			return (0);
	}
	// system("leaks a.out");
	return(0);
}