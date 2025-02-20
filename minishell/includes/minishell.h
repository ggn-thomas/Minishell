/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:34:37 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/20 14:39:17 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include "../libft/libft.h"
/*
typedef enum s_mode
{
	word,
	pipe,
	r_input,
	r_ouput,
	echo,
	cd,
	pwd,
	eexport,
	unset,
	env,
	exit,
	single_q,
	double_q,
	env_var,
}	t_mode;*/


typedef struct	s_line
{
	char	*data;
	struct s_line	*next;
	struct s_line	*prev;
}	t_line;

//tokenisation && parsing
char	**ft_split_operator(char const *s);
t_line	**check_operator_glued(char *str, t_line **line);
void	tokenisation(char *line);

//utils parsing
int	have_operator_glued(char *str);
void	had_token_in_list(char *tab_line, t_line **list_token);
t_line	*ft_new_node(char	*content);
void	ft_lst_add_back(t_line **lst, t_line *new);
t_line	*ft_lst_last(t_line *lst);

//free
void	ft_free_list(t_line	**list);
void	ft_free_tab(char **str);

#endif