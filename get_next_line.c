/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:54:00 by mosborne          #+#    #+#             */
/*   Updated: 2017/12/17 15:09:22 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static char *find_eof(int fd, char *buf, int *ret)
{
    char tmp[BUFF_SIZE + 1];
    char *tmpfree;

    *ret = read(fd, tmp, BUFF_SIZE);
    if (ret > 0)
    {
        tmp[*ret] = '\0';
        tmpfree = buf;
        buf = ft_strjoin(buf, tmp);
        ft_strdel(tmpfree);
    }
    return (buf);
}

int         get_next_line(const int fd, char **line)
{
    int         ret;
    char        *str;
    static char *buf;

    if (fd < 0 || BUFF_SIZE < 1 || !line)
        return (-1);
    buf = ft_strnew(BUFF_SIZE);
    while ((ret = read(fd, str, BUFF_SIZE)) > 0)
    {
        if ((str = ft_strchr(buf, '\n')) != NULL)
        {
            *str = '\0';
            *line = ft_strdup(buf);
            ft_memmove(buf, str + 1, ft_strlen(str + 1) + 1);
            return (1);
        }
        buf = find_eof(fd, buf, &ret);
    }
    return (ret);
}
