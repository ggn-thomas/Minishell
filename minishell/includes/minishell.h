/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:34:37 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/24 15:37:10 by thomas           ###   ########.fr       */
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
#include <signal.h>
#include <sys/types.h>

typedef enum s_mode
{
	WORD,
	PIPE,
	R_INPUT,
	R_OUPUT,
	ECHO,
	CD,
	PWD,
	EEXPORT,
	UNSET,
	ENV,
	EXIT,
	SINGLE_Q,
	DOUBLE_Q,
	ENV_VAR,
}	t_mode;

typedef struct	s_line
{
	char	*data;
	t_mode	mode;
	struct s_line	*outfile;
	struct s_line	*infile;
	struct s_line	*next;
	struct s_line	*prev;
}	t_line;

//tokenisation && parsing
char	**ft_split_operator(char const *s);
t_line	**check_operator_glued(char *str, t_line **line);
int	tokenisation(char *line);
void    signal_handler(int signint);

//utils parsing
int	have_operator_glued(char *str);
void	had_token_in_list(char *tab_line, t_line **list_token);
t_line	*ft_new_node(char	*content);
void	ft_lst_add_back(t_line **lst, t_line *new);
t_line	*ft_lst_last(t_line *lst);
void	check_type(t_line *list_token);

//free
void	ft_free_list(t_line	**list);
void	ft_free_tab(char **str);

#endif