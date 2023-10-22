/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:18:45 by lvichi            #+#    #+#             */
/*   Updated: 2023/10/22 15:47:53 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	size = nmemb * size;
	ret = malloc(size);
	if (!ret)
		return (NULL);
	while (size)
		((char *)ret)[--size] = 0;
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] || (unsigned char)c == '\0')
		if (s[i++] == (unsigned char)c)
			return (&((char *)s)[i - 1]);
	return (0);
}

char	*ft_strcat(char *str_first, char *str_second)
{
	char	*str;
	int		i;
	int		t;

	if (!str_second)
		return (str_first);
	str = (char *)malloc(ft_strlen(str_first) + ft_strlen(str_second) + 1);
	if (!str)
		return (NULL);
	i = 0;
	t = 0;
	while (str_first[i])
		str[t++] = str_first[i++];
	i = 0;
	while (str_second[i])
		str[t++] = str_second[i++];
	str[t] = 0;
	free(str_first);
	free(str_second);
	return (str);
}
