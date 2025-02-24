/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:57:14 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/24 16:20:50 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_print_list(t_line **list_token)
{
	t_line	*tmp;

	tmp = *list_token;
	while (tmp)
	{
		printf("%s | type : %u\n", tmp->data, tmp->mode);
		tmp = tmp->next;
	}
}

static void	create_list(char **tab_line, t_line **list_token)
{
	int	i;

	i = 0;
	while (tab_line[i])
	{
		if (have_operator_glued(tab_line[i]))
			check_operator_glued(tab_line[i], list_token);
		else
			had_token_in_list(tab_line[i], list_token);
		i++;
	}
	ft_free_tab(tab_line);
}

void	check_type(t_line *list_token)
{
	if (ft_strcmp(list_token->data, "cd") == 0)
		list_token->mode = CD;
	else if (ft_strcmp(list_token->data, "|") == 0)
		list_token->mode = PIPE;
	else if (ft_strcmp(list_token->data, ">") == 0)
		list_token->mode = R_INPUT;
	else if (ft_strcmp(list_token->data, "<") == 0)
		list_token->mode = R_OUPUT;
	else if (ft_strcmp(list_token->data, "echo") == 0)
		list_token->mode = ECHO;
	else if (ft_strcmp(list_token->data, "export") == 0)
		list_token->mode = EEXPORT;
	else if (ft_strcmp(list_token->data, "unset") == 0)
		list_token->mode = UNSET;
	else if (ft_strcmp(list_token->data, "env") == 0)
		list_token->mode = ENV;
	else if (ft_strcmp(list_token->data, "pwd") == 0)
		list_token->mode = PWD;
	else if (ft_strcmp(list_token->data, "exit"))
		list_token->mode = EXIT;
	else
		list_token->mode = WORD;
}

int	tokenisation(char *line)
{
	t_line	**list_token;
	char	**tab_line;

	list_token = malloc(sizeof(t_line *));
	*list_token = NULL;
	tab_line = ft_split_operator(line);
	if (!tab_line)
		return (0);
	create_list(tab_line, list_token);
	//check_quotes(list_token);
	ft_print_list(list_token);// temporaire
	return (1);
}