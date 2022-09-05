/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:13:58 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/25 15:52:23 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_env(char *env, char *cmd, int i, int j)
{
	int	c[2];

	c[0] = 0;
	c[1] = 0;
	while (cmd[i])
	{
		ft_quote(cmd, i, c);
		if (cmd[i] == '$')
		{
			j = i++;
			if (cmd[i] && !c[1] && cmd[i] == '?')
				ft_env_state_return(&cmd, &i, j);
			else if (cmd[i] && !c[1] && !ft_isdigit(cmd[i])
				&& ft_env_char(cmd[i]))
				ft_env_default(&cmd, &i, j, env);
			else if (cmd[i] && !c[1] && ft_isdigit(cmd[i]))
				ft_env_digit(&cmd, &i, j);
		}
		else if (cmd[i] && !c[1] && !c[0] && cmd[i] == '~'
			&& ft_is_tild(cmd, i))
			ft_env_tild(&cmd, &i, env);
		if (cmd[i])
			i++;
	}
	return (cmd);
}
