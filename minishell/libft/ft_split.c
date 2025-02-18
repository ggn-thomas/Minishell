/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:48:40 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/18 15:47:43 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static int	ft_count_letter(char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**ft_fill(char **dest, int i, int len, char const *s)
{
	dest[i] = malloc(sizeof(char) * (len + 1));
	if (!dest[i])
	{
		while (i > 0)
		{
			free(dest[i - 1]);
			i--;
		}
		free(dest);
		return (NULL);
	}
	ft_strlcpy(dest[i], s, len + 1);
	dest[i][len] = '\0';
	return (dest);
}

static int	ft_check(char const *s, char c)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(s);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			j++;
		i++;
	}
	if (j == len)
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (!(ft_check(s, c)) || s == NULL)
		return (NULL);
	dest = malloc(sizeof(char *) * (ft_count_word((char *)s, c) + 1));
	if (!dest)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = ft_count_letter((char *)s, c);
			if (!ft_fill(dest, i++, len, s))
				return (NULL);
			s += len;
		}
		else
			s++;
	}
	dest[i] = NULL;
	return (dest);
}
