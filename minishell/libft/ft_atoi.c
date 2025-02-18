/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:05:25 by thgaugai          #+#    #+#             */
/*   Updated: 2024/10/16 14:51:52 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		nb;
	int		r;
	char	*str;

	str = (char *)nptr;
	i = 0;
	nb = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i + 1] == '+' || str[i + 1] == '-')
			return (0);
		else if (nptr[i] == '-')
			nb *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	return (r * nb);
}
