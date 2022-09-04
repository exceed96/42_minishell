/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd_9.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:18:31 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 19:56:27 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_run_cmd_9(t_data *data, t_in_out *inout)
{
	(void)inout;
	data->line = NULL;
	close(data->fd[data->c_n * 2 + 1]);
	if (pipe(data->fd + 2 * data->c_n) < 0)
		ft_perror("pipe failed", 1);
	while (data->inout->next && data->inout->next->type == 3)
		data->inout = data->inout->next;
	write(data->fd[data->c_n * 2 + 1], data->inout->heredoc,
		ft_strlen(data->inout->heredoc));
}
