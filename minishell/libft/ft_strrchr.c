/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:31:17 by thgaugai          #+#    #+#             */
/*   Updated: 2024/10/17 16:16:43 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	s += i;
	while (i >= 0)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s--;
		i--;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (NULL);
}
