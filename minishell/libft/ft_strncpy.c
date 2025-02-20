/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:02:45 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/20 14:47:13 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i ;
	unsigned int	j ;

	j = 0;
	i = 0;
	while ((src[i] == '|' || src[i] == '>' || src[i] == '<') && src[i])
		i++;
	while (i < n && src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}
	return (dest);
}
