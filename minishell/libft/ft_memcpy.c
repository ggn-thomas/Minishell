/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:44:01 by thgaugai          #+#    #+#             */
/*   Updated: 2024/10/11 12:30:11 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*d;
	char	*s;

	d = dest;
	s = (void *)src;
	i = 0;
	if (!dest && !src)
		return ((void *)d);
	while (n--)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *)d);
}
