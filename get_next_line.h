/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:54:14 by mosborne          #+#    #+#             */
/*   Updated: 2017/12/18 16:50:13 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "./libft/libft.h"

# define BUFF_SIZE 1

int         get_next_line(const int fd, char **line);
static char *read_fd(int fd, char *buf, int ret);

#endif