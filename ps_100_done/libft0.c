/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:30:18 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/10 18:47:58 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	free_ft_split_inter(char ***splited, int j)
{
	while (!(*splited)[j - 1])
	{
		free((*splited)[j - 1]);
		if (--j == 0)
		{
			free((*splited));
			*splited = NULL;
			return ;
		}
	}
}

static void	ft_split_inter(char ***splited, const char *s, char c)
{
	int	j;
	int	d;
	int	i;

	j = 0;
	d = 0;
	i = 0;
	while (*splited && (*splited)[j] && s[d])
	{
		if (s[d] == c && s[d + 1] != c)
			i = d + 1;
		if ((s[d++] != c && s[d] == c) || (s[d - 1] != c && s[d] == '\0'))
		{
			(*splited)[j++] = (char *) malloc(d - i + 1);
			free_ft_split_inter(splited, j);
			if (!*splited)
				return ;
			(*splited)[j - 1] = ft_memcpy((*splited)[j - 1], s + i, d - i);
			(*splited)[j - 1][d - i] = '\0';
		}
	}	
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
	while (s[d] && s[d] == c)
		d++;
	while (s[d])
		if ((s[d++] != c && s[d] == c) || (s[d - 1] != c && s[d] == '\0'))
			i++;
	splited = (char **)malloc((i + 1) * sizeof(char *));
	if (!splited)
		return (0);
	splited[i] = NULL;
	ft_split_inter(&splited, s, c);
	return (splited);
}
