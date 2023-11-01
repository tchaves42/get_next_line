/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchaves <tchaves@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:13:26 by tchaves           #+#    #+#             */
/*   Updated: 2023/11/01 15:33:21 by tchaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	if (!str)
		return (0);
	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*ft_strdup(char *src)
{
	char	*ret;
	int		c;

	c = ft_strlen(src) + 1;
	ret = malloc(c * sizeof(*ret));
	if (!ret)
		return (ret);
	c = 0;
	while (src[c])
	{
		ret[c] = src[c];
		c++;
	}
	ret[c] = 0;
	return (ret);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	if (destsize == 0)
		return (ft_strlen((char *)src));
	while (src[i] && i < destsize - 1 && i != destsize)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (ft_strlen((char *)src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	newstr = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!newstr)
		return (newstr);
	ft_strlcpy(newstr, s1, ft_strlen(s1) + 1);
	ft_strlcpy(newstr + ft_strlen(s1), s2, ft_strlen((char *)s2) + 1);
	free(s1);
	free(s2);
	return (newstr);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if ((char)c == s[i])
			return (i);
		i++;
	}
	if ((char)c == s[i])
		return (i);
	return (-1);
}