/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:44:52 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/20 12:45:17 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, int n)
{
	int			i;
	int			len;
	char		*dest;

	len = n;
	i = 0;
	if (s == NULL)
		return (NULL);
	dest = malloc(sizeof (char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i] && i < n)
	{
		dest[i] = (char)s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}