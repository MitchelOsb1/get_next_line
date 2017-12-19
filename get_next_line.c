/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:54:00 by mosborne          #+#    #+#             */
/*   Updated: 2017/12/18 16:50:14 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char *read_fd(int fd, char *buf, int ret)
{
    char tmp[BUFF_SIZE + 1];

    
    ret = read(fd, tmp, BUFF_SIZE);
    if (ret > 0)
    {
        tmp[ret] = '\0';
        buf = ft_strjoin(buf, tmp);
    }
    return (buf);
}

int         get_next_line(const int fd, char **line)
{
    int         ret;
    char        *str;
    static char *buf;

    if (fd < 0 || BUFF_SIZE < 0 || !line)
        return (-1);
    buf = ft_strnew(BUFF_SIZE);
    str = ft_strchr(buf, '\n');
    while (str == NULL)
    {
        buf = read_fd(fd, buf, ret);
        if (ret < 0)
        {
            *str = '\0';
            *line = ft_strdup(buf);
            ft_memmove(buf, str + 1, ft_strlen(str + 1) + 1);
            return (1);
        }
    }
    return (ret);
}

// int	main(void)
// {
// 	char	*str;
// 	int		fd;
// 	int		result;

// 	if ((fd = open("test.txt", O_RDONLY)) < 0)
// 		return (0);
// 	while ((result = get_next_line(fd, &str)) > 0)
// 	{
// 		printf("%s\n", str);
// 		free(str);
// 	}
// 	close(fd);
// 	return (0);
// }