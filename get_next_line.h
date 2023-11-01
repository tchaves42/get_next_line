/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchaves <tchaves@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:13:20 by tchaves           #+#    #+#             */
/*   Updated: 2023/11/01 15:35:28 by tchaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(char *src);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strchr(const char *s, int c);
char	*ft_read(int fd);
char	*check_line(char *stored_buf, char *line, int newline_index);
char	*check_end(char *stored_buf, char *temp);
char	*get_next_line(int fd);

#endif