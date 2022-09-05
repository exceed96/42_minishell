/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd_8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:26:09 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 19:54:12 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_run_cmd_8(t_data *data, t_process **tmp, char **senv, int i)
{
	int	c;
	int	c2;

	c = 0;
	c2 = 0;
	while (i >= 0 && data->inout && data->inout->type == 1)
	{
		if (c >= 0)
		{
			ft_pipe_process_5(data, (*tmp), senv, i);
			c = open(ft_search_quote_2(data->inout->file, 0), O_RDONLY);
			c2 = 1;
		}
		if (c2 == 1)
		{
			close(c);
			c2 = 0;
		}
		if (!data->inout && !(*tmp)->output_fd && (*tmp)->cmd
			&& !ft_cmd((*tmp)->cmd, "exit"))
			exit(0);
		data->inout = data->inout->next;
		i--;
	}
	return (i);
}
