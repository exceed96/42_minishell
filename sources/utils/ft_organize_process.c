/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_organize_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:19:36 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/02 12:59:10 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_organize_process(t_process *process, int i, int next, int inout)
{
	t_process	*tmp;

	tmp = process;
	while (tmp && ++i < ft_structlen(process))
	{
		if (tmp->type && tmp->type[0] == '|')
		{
			if (i)
				tmp->input_fd = 1;
			tmp->output_fd = 1;
			next = 1;
			if (tmp->inout)
				inout = 1;
		}
		else if (next)
		{
			tmp->input_fd = 1;
			inout = 0;
			next = 0;
		}
		if (tmp->inout)
			ft_organize_inout(tmp->inout);
		ft_clear_process(tmp);
		tmp = tmp->next;
	}
}
