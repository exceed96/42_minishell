/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:36:42 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/31 15:38:30 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_clean_process(t_process *process)
{
	t_process	*tmp;
	t_in_out	*tmp_io;

	tmp = process;
	while (tmp)
	{
		if (tmp->cmd && !ft_strlen(tmp->cmd))
		{
			free(tmp->cmd);
			tmp->cmd = NULL;
		}
		tmp_io = tmp->inout;
		while (tmp_io)
			tmp_io = tmp_io->next;
		tmp = tmp->next;
	}
}
