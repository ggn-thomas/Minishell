/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:10:38 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/20 14:41:03 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_line	*ft_lst_last(t_line *lst)
{
	t_line	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lst_add_back(t_line **lst, t_line *new)
{
	t_line	*last ;

	if (!lst || !new)
		return ;
	last = ft_lst_last(*lst);
	if (!last)
		*lst = new ;
	else
		last->next = new ;
}

void	had_token_in_list(char *tab_line, t_line **list_token)
{
	t_line	*tmp;

	tmp = ft_new_node(tab_line);
	ft_lst_add_back(list_token, tmp);
}

int	have_operator_glued(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|' || str[i] == '>' || str[i] == '<')
			return (1);
		i++;
	}
	return (0);
}
