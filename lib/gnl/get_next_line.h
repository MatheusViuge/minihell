/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:07:20 by jesda-si          #+#    #+#             */
/*   Updated: 2024/11/08 20:07:50 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include "../libft.h"

char	*get_next_line(int fd);
char	*read_fd(int fd, ssize_t *len);
size_t	ft_linelen(char *str, int line);
char	*ft_strncpy(char *dest, char *src, ssize_t size);
char	*ft_subline(char *s, int line);
char	*ft_join_buffer(char *buffer, char *read);
char	*free_str(char *str);
char	*div_buffer(char **buffer);

#endif
