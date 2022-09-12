/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:06:59 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/10 18:10:35 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*ft_get_params(t_cmd *cmd, char **tmp[2], int *i)
{
	if (tmp[0][*i])
	{
		if (tmp[0][*i][0] == '>' && tmp[0][*i + 1] && tmp[0][*i + 1][0] == '>')
			cmd = ft_get_outfile(cmd, tmp[1], i);
		else if (tmp[0][*i][0] == '>')
			cmd = ft_get_outfile_2(cmd, tmp[1], i);
		else if (tmp[0][*i][0] == '<' && tmp[0][*i + 1]
				&& tmp[0][*i + 1][0] == '<')
			cmd = ft_get_infile(cmd, tmp[1], i);
		else if (tmp[0][*i][0] == '<')
			cmd = ft_get_infile_2(cmd, tmp[1], i);
		else if (tmp[0][*i][0] != '|')
			cmd->f_cmd = ft_extend_split(cmd->f_cmd, tmp[1][*i]);
		else
		{
			ft_perror(PIPERR, NULL, 2);
			*i = -2;
		}
		return (cmd);
	}
	ft_perror(PIPERR, NULL, 2);
	*i = -2;
	return (cmd);
}
