/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:34:04 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/20 13:00:14 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_list(t_line	**list)
{
	t_line	*remove;
	t_line	*tmp;
	
	tmp = *list;
	while (tmp)
	{
		remove = tmp;
		tmp = tmp->next;
		free(remove->data);
		free(remove);
	}
	free(list);
}