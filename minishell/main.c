/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:49:39 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/24 16:41:45 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(int ac, char **av, char **env)
{

	(void)ac;
	(void)av;
	(void)env;
	char	*rl;
	struct sigaction	sa;
	
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigaction(SIGQUIT, &sa, 0);
	sigaction(SIGINT, &sa, 0);
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);// définit un gestionnaire pour le signal : SIGQUIT (ctrl -\), et l'ignore avec SIG_IN (signifie ingnore)
		rl = readline("-> bash> ");
		if (!rl)
		{
			free(rl);
			printf("exit\n");
			break ;
		}
		tokenisation(rl);
		add_history(rl);
		free(rl);
	}
	return (0);
}