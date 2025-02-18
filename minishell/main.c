/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:49:39 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/18 16:59:19 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(int ac, char **av)
{
	int	i;
	char	*tmp;
	char	*line;
	char	**tab_token;

	(void)ac;
	i  = 1;
	while (av[i])
	{
		if (i == 1)
			tmp = ft_strdup("");
		else
			tmp = line;
		line = ft_strjoin(tmp, av[i]);
		free(tmp);
		i++;
	}
	printf("%s", line);
	tab_token = ft_split_operator(line);
	i = 0;
	while (tab_token[i])
	{
		printf("%s\n", tab_token[i]);
		i++;
	}
	ft_free_tab(tab_token);
	return (0);
}