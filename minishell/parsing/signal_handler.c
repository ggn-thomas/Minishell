/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:06:02 by thomas            #+#    #+#             */
/*   Updated: 2025/02/24 16:22:10 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    signal_handler(int signint)
{
    if (signint == SIGINT)
    {
        printf("\n"); // = nouvelle ligne
        rl_on_new_line(); // indique qu'on créé une nouvelle ligne sinon il est pommé
        rl_replace_line("", 0);// on efface ce qui était sur la ligne en cours d'éxection
        rl_redisplay();// on réaffiche le prompt
        return ;
    }
    else if (signint == SIGQUIT)
    {
        printf("helo");
        return ;
    }
}