/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:57:14 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/20 14:20:55 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_print_list(t_line **list_token)
{
	t_line	*tmp;

	tmp = *list_token;
	while (tmp)
	{
		printf("%s\n", tmp->data);
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
	ft_print_list(list_token);
}