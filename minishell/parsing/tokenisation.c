/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:57:14 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/21 13:01:41 by thgaugai         ###   ########.fr       */
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
}
static void	check_type(t_line **list_token)
{
	t_line	*index;

	index = *list_token;
	while (index)
	{
		if (ft_strcmp(index->data, "cd") == 0)
			index->mode = CD;
		else if (ft_strcmp(index->data, "|") == 0)
			index->mode = PIPE;
		else if (ft_strcmp(index->data, ">") == 0)
			index->mode = R_INPUT;
		else if (ft_strcmp(index->data, "<") == 0)
			index->mode = R_OUPUT;
		else if (ft_strcmp(index->data, "echo") == 0)
			index->mode = ECHO;
		else if (ft_strcmp(index->data, "export") == 0)
			index->mode = EEXPORT;
		else if (ft_strcmp(index->data, "unset") == 0)
			index->mode = UNSET;
		else if (ft_strcmp(index->data, "env") == 0)
			index->mode = ENV;
		else if (ft_strcmp(index->data, "pwd") == 0)
			index->mode = PWD;
		else if (ft_strcmp(index->data, "exit"))
			index->mode = EXIT;
		else
			index->mode = WORD;
		index = index->next;
	}
}

void	tokenisation(char *line)
{
	t_line	**list_token;
	char	**tab_line;

	list_token = malloc(sizeof(t_line *));
	*list_token = NULL;
	tab_line = ft_split_operator(line);
	if (!tab_line)
		return ;
	create_list(tab_line, list_token);
	check_type(list_token);
	ft_print_list(list_token);
}