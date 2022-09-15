/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:41:54 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/14 12:10:06 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cmd_env(t_data *data)
{
	char	**str[2];
	int		i;

	i = 0;
	str[0] = ((t_cmd *)data->cmds->content)->f_cmd;
	if (str[0][1])
	{
		printf("env : %s: No such file or directory\n", str[0][1]);
		return (127);
	}
	while (data->env[i])
		printf("%s\n", data->env[i++]);
	return (0);
}
