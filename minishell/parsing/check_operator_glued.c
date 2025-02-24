/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operator_glued.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:49:00 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/24 10:18:20 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_line	*ft_new_node(char	*content)
{
	t_line	*new_node;

	new_node = malloc(sizeof(t_line));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->data = ft_strdup(content);
	return (new_node);
}

static int	add_before_op(char *str, int len, t_line **line)
{
	char	*tmp;
	t_line	*new_node;

	tmp = malloc(len + 1);
	if (!tmp)
		return (0);
	ft_strncpy(tmp, str, len);
	tmp[len] = '\0';
	new_node = ft_new_node(tmp);
	check_type(new_node);
	ft_lst_add_back(line, new_node);
	free(tmp);
	return (1);
}

static int	add_next_op(char *str, int i, t_line **line)
{
	char	*tmp;
	t_line	*new_node;
	int	n;

	n = i + 1;
	while (str[n] != '|' && str[n] != '<' && str[n] != '>' && str[n])
		n++;
	tmp = ft_strndup(&str[i + 1], n - i - 1);
	if (tmp && tmp[0] != '\0')
	{
		new_node = ft_new_node(tmp);
		check_type(new_node);
		ft_lst_add_back(line, new_node);
		free(tmp);
	}
	else if (tmp)
		free(tmp);
	return (n - i);
}

static void	add_operator(char operator, t_line **line)
{
	t_line	*new_node;
	char	tab_operator[2];

	tab_operator[0] = operator;
	tab_operator[1] = '\0';
	new_node = ft_new_node(tab_operator);
	check_type(new_node);
	ft_lst_add_back(line, new_node);
}

t_line	**check_operator_glued(char *str, t_line **line)
{
	int	i;
	int	n = 0;

	i = 0;
	if (str[0] == '|' || str[0] == '<' || str[0] == '>')
	{
		add_operator(str[0], line);
		i++;
	}
	while (str[i] != '|' && str[i] != '<' && str[i] != '>' && str[i])
		i++;
	add_before_op(str, i, line);
	while (str[i])
	{
		while (str[i] != '|' && str[i] != '<' && str[i] != '>' && str[i])
			i++;
		add_operator(str[i], line);
		n = add_next_op(str, i , line);
		i += n;
	}
	return (line);
}