/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:49:27 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/27 17:04:29 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_split(char *cmd, int i, int j, int pipe)
{
	char	**str;
	char	c;

	str = ft_env_split(str, ' ');
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			ft_eheck_quote_cmd(cmd, i, &j, &c);
			if (str[i][j])
			{
				if (str[i][j] == '|')
					pipe++;
				else
					pipe = 0;
				if (pipe == 2 || (str[i][j + 1] && str[i][j] == '|'
						&& str[i][j + 1] == '|'))
					return (ft_free_split(str, 0));
			}
		}
	}
	if (cmd[0][0] == '|' || pipe)
		return (ft_free_split(str, 0));
	return (ft_free_split(str, 1));
}
