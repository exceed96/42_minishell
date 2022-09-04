/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:23:20 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/02 12:51:11 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_n_cmd(t_process **process, char **cmd, int i, int j)
{
	j = ft_n_space(cmd[i]);
	(*process)->cmd = ft_strndup(cmd[i] + j, ft_wordlen2(cmd[i] + j));
	(*process)->cmd_arg = ft_strdup((*process)->cmd);
	(*process)->cmd_arg = ft_strnjoin((*process)->cmd_arg, " ", 1);
	j += ft_wordlen2(cmd[i] + j);
	return (j);
}
