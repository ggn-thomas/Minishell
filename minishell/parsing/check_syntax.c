/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:07:24 by thomas            #+#    #+#             */
/*   Updated: 2025/02/24 10:20:13 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int check_quotes(char *str)
{
    int i ;
    int count_d_quote;
    int count_s_quote;
    char *rl;

    count_d_quote = 0;
    count_s_quote = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == '"')
            count_d_quote++;
        else if (str[i] == '\'')
            count_s_quote++;
        i++;
    }
    if (count_d_quote % 2 != 0 || count_s_quote % 2 != 0)
    {
        while (1)
        {
            rl = readline("-> quote> ");
		    add_history(rl);
		    free(rl);
        }
    }
    return (1);
}