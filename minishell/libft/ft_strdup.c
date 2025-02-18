/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:33:41 by thgaugai          #+#    #+#             */
/*   Updated: 2024/10/17 16:15:15 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int			i;
	int			len;
	char		*dest;

	len = ft_strlen(s);
	i = 0;
	if (s == NULL)
		return (NULL);
	dest = malloc(sizeof (char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = (char)s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
