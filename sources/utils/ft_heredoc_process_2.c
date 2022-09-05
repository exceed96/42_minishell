/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_process_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:00:33 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/31 16:08:52 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_heredoc_process_2(t_in_out *inout, char *tmp_r, char *r_l, char *str)
{
	r_l = readline("> ");
	if (tmp_r)
		free(tmp_r);
	tmp_r = ft_strdup("");
	while (r_l)
	{
		if (!ft_is_cmd(r_l, inout->file))
		{
			inout->heredoc = ft_env(str, tmp_r, 0, 0);
			free(r_l);
			break ;
		}
		else
		{
			tmp_r = ft_strnjoin(tmp_r, r_l, ft_strlen(r_l));
			tmp_r = ft_strnjoin(tmp_r, "\n", 1);
		}
		free(r_l);
		r_l = readline("> ");
	}
	if (!r_l)
	{
		inout->heredoc = ft_env(str, tmp_r, 0, 0);
		free(r_l);
	}
}
