/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:34:29 by thgaugai          #+#    #+#             */
/*   Updated: 2024/10/10 14:56:11 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int		i ;
	char	*str ;

	i = 0;
	str = s;
	while (n--)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return ((void *)str);
}
