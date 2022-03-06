/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:30:18 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/06 13:01:32 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief print a string in file descriptor
 *
 * @param s string to print in file descriptor fd 
 * @param fd  file descriptor
 */
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s && s[++i])
		write (fd, s + i, 1);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (!dst && !src)
		return (NULL);
	while (++i < n)
	{
		*((unsigned char *)(dst + i)) = *((unsigned char *)(src + i));
	}
	return (dst);
}

static int fill(char **splited, const char *s, int len, int j)
{

	splited[j] = (char *) malloc(len + 1);
	while (!splited[j])
	{
		free(splited[j]);
		if (j < 0)
		{
			free(splited);
			return (0);
		}
	}
	splited[j] = ft_memcpy(splited[j], s, len);
	splited[j][len] = '\0';
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;
	int		i;
	int		d;
	int		j;

	i = 0;
	j = 0;
	d = 0;
	if (!s)
		return (0);
	while (s[d] && s[d] == d)
		d++;
	while (s[d])
		if ((s[d++] != c && s[d] == c) || (s[d - 1] != c && s[d] == '\0'))
			i++;
	splited = (char **)malloc((i + 1) * sizeof(char *));
	if (!splited)
		return (0);
	splited[i] = NULL;
	d = 0;
	while (splited && s[d])
	{
		if (s[d] == c && s[d + 1] != c)
			i = d + 1;
		if ((s[d++] != c && s[d] == c) || (s[d - 1] != c && s[d] == '\0'))
		{
			if (!fill(splited, s + i, d - i, j++))
			{
				free(splited);
				return (NULL);
			}
		}
	}	
	return (splited);
}
