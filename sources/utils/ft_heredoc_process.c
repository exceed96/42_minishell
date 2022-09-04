/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:44:51 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/02 12:47:47 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_heredoc_process(t_process *process, char *str)
{
	t_process	*tmp;
	t_in_out	*inout;
	char		*read_line;
	char		*tmp_r;

	tmp = process;
	read_line = NULL;
	tmp_r = NULL;
	while (tmp)
	{
		if (tmp->inout)
		{
			inout = tmp->inout;
			while (inout)
			{
				inout->heredoc = NULL;
				if (inout->type == 3)
					ft_heredoc_process_2(inout, tmp_r, read_line, str);
				inout = inout->next;
			}
		}
		tmp = tmp->next;
	}
}
