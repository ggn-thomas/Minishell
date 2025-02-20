/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:49:39 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/20 14:16:50 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
/*
static void	ft_print(char **str)
{
	int	i = 0;

	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}*/

int	main(int ac, char **av, char **env)
{

	(void)ac;
	(void)av;
	(void)env;
	char	*rl;

	while (1)
	{
		rl = readline("-> bash> ");
		tokenisation(rl);
		add_history(rl);
		free(rl);
	}
	return (0);
}