/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:33:59 by thomas            #+#    #+#             */
/*   Updated: 2024/10/15 16:58:08 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len++;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long		nbr;
	int			i;
	int			len;
	char		*dest;

	nbr = n;
	len = ft_intlen(nbr);
	i = 0;
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	dest[0] = '0';
	if (nbr < 0)
	{
		nbr *= -1;
		dest[0] = '-';
	}
	i = len - 1;
	while (nbr != 0)
	{
		dest[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	dest[len] = '\0';
	return (dest);
}
