/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:33:16 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/31 15:35:38 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_clear_process(t_process *process)
{
	char	**str;

	if (ft_strlen(process->cmd_arg) && !ft_strlen(process->cmd))
	{
		str = ft_env_split(process->cmd_arg, ' ');
		process->cmd = ft_strdup(str[0]);
		ft_free_split(str);
	}
}
