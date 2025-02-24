/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:48:30 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/24 08:33:13 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


static int	ft_count_word(char *s)
{
	int	i;
	int	count;
	int	in_quotes;

	in_quotes = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		while ((s[i] == '\t' || s[i] == '\n' || s[i] == ' ') && s[i] && !in_quotes)
			i++;
		if (s[i])
		{
			if (s[i] == '"')
			{
				in_quotes = 1;
				i++;
			}
			count++;
			while (s[i] && ((s[i] != '\n' && s[i] != '\t' && s[i] != ' ' && !in_quotes) || (in_quotes && s[i] != '"')))
				i++;
			if (s[i] == '"')
			{
				in_quotes = 0;
				i++;
			}
		}
	}
	return (count);
}

static int	ft_count_letter(char *s)
{
	int	len;

	len = 0;
	if (s[len] == '"')
	{
		len++;
		while  (s[len] && s[len] != '"')
			len++;
		if (s[len] == '"')
			len++;
		return (len);
	}
	while (s[len] && (s[len] != ' ' && s[len] != '\n' && s[len] != '\t'))
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

char	**ft_split_operator(char const *s)
{
	char	**dest;
	int		i;
	int		len;
	int	in_quotes;

	len = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	dest = malloc(sizeof(char *) * (ft_count_word((char *)s) + 1));
	if (!dest)
		return (NULL);
	while (*s)
	{
		if (*s == '"')
			in_quotes = 1;
		if ((*s != '\n' && *s != '\t' && *s != ' ') && in_quotes)
		{
			len = ft_count_letter((char *)s);
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
