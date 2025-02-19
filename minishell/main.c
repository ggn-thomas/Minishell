/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:49:39 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/19 13:56:34 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static void	ft_print(char **str)
{
	int	i = 0;

	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}

int	main(int ac, char **av, char **env)
{

	(void)ac;
	(void)av;
	(void)env;
	char	*rl;
	char	**tab_word;

	while (1)
	{
		rl = readline("-> bash> ");
		tab_word = ft_split_operator(rl);
		ft_print(tab_word);
		add_history(rl);
		free(rl);
	}
	return (0);
}