/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:09:59 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/14 17:10:01 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_my_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*get_temp(int fd, char *temp)
{
	char	*buff;
	int		len;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	len = 1;
	while (!ft_strchr(temp, '\n') && len)
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[len] = '\0';
		temp = ft_my_strjoin(temp, buff);
	}
	free(buff);
	return (temp);
}

char	*get_str(char *temp)
{
	char	*str;
	int		i;

	i = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
	{
		str[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
	{
		str[i] = temp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_temp(char *temp)
{
	char	*str;
	int		i;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	str = (char *)malloc(ft_strlen(temp) - i + 1);
	if (!str)
		return (NULL);
	str = ft_strcpy(str, &temp[++i]);
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*temp[65536];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp[fd] = get_temp(fd, temp[fd]);
	if (!temp[fd])
		return (NULL);
	str = get_str(temp[fd]);
	temp[fd] = get_next_temp(temp[fd]);
	return (str);
}
