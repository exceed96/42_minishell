/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:29:18 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/02 12:57:46 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_direction(t_process **process, int i, int *j, char **cmd)
{
	int			x;
	char		c;
	t_in_out	*tmp;

	ft_made(&x, &c, cmd[i][(*j)]);
	tmp = ft_create_inout();
	if (cmd[i][(*j) + 1] && (cmd[i][(*j) + 1] == c))
	{
		if (c == '<')
			tmp->type = 3;
		else if (c == '>')
			tmp->type = 4;
		(*j)++;
	}
	else
	{
		if (c == '<')
			tmp->type = 1;
		else if (c == '>')
			tmp->type = 2;
	}
	(*j) += ft_n_space(cmd[i] + (*j) + 1) + 1;
	tmp->file = ft_strndup(cmd[i] + (*j), ft_quote_len(cmd[i] + (*j)));
	(*j) += ft_quote_len(cmd[i] + (*j));
	ft_push(&(*process)->inout, tmp);
}
