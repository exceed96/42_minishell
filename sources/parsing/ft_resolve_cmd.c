/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:41:42 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/04 13:17:00 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_resolve_cmd(char *cmd, char **env, char **s_env, char *tmp)
{
	t_process	*process;
	int			i;

	i = 0;
	if (!ft_space(cmd) || !ft_strlen(cmd))
		return ;
	if (ft_check_quote(cmd) && ft_check_split(cmd, -1, 0, 0))
	{
		process = ft_create_process(-1, 0, ft_env_split(cmd, 'l'));
		if (ft_check_process(process))
		{
			ft_organize_process(process, -1, 0, 0);
			ft_clean_process(process);
			ft_heredoc_process(process, tmp);
			g_status_number = ft_run_cmd(process, env, s_env);
			i = 1;
		}
		else
			printf("zsh: syntax error near 'newline'\n");
		ft_free(&process);
	}
	if (!i)
		g_status_number = 258;
}
