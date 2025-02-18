/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:25:40 by thgaugai          #+#    #+#             */
/*   Updated: 2024/10/17 16:16:11 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j] && size)
	{
		if (size && i < size - 1)
		{
			dst[i] = (char)src[i];
			i++;
		}
		j++;
	}
	if (size)
		dst[i] = '\0';
	return (ft_strlen(src));
}
