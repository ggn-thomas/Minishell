/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:49:48 by thomas            #+#    #+#             */
/*   Updated: 2024/12/03 10:23:16 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if ((char)set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_str(char const *s1, int start, int end)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = 0;
	len = end - start;
	if (end <= 0 || (size_t)start >= ft_strlen(s1))
		return (ft_strdup(""));
	dest = ft_calloc(len + 2, sizeof(char));
	if (!dest)
		return (NULL);
	while (start <= end)
	{
		dest[i] = s1[start];
		i++;
		start++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	if (ft_strlen((char *)s1) == 0)
		return (ft_strdup(""));
	j = ft_strlen((char *)s1) - 1;
	i = 0;
	while (ft_counter(s1[i], set))
		i++;
	while (ft_counter(s1[j], set))
		j--;
	return (ft_str(s1, i, j));
}
