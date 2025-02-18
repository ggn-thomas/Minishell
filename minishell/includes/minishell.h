/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:34:37 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/18 16:51:00 by thgaugai         ###   ########.fr       */
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


typedef struct	s_word
{
	char	*data;
	struct s_word	*next;
	struct s_word	*prev;
}	t_word;

void	ft_free_tab(char **str);
char	**check_type(t_word *node);
char	**ft_split_operator(char const *s);
#endif