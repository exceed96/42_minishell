/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:49:27 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/04 18:42:02 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_split(char *cmd, int i, int j, int pipe)
{
	char	**str;
	char	c;

	str = ft_env_split(cmd, ' ');
	while (str[++i])
	{
		j = 0;
		while (str[i][j])
		{
			ft_check_quote_cmd(str, i, &j, &c);
			if (str[i][j])
			{
				if (str[i][j] == '|')
					pipe++;
				else
					pipe = 0;
				if (pipe == 2 || (str[i][j + 1] && str[i][j + 1] == '|'
						&& str[i][j++] == '|'))
					return (ft_free_split_r(str, 0));
			}
		}
	}
	if (str[0][0] == '|' || pipe)
		return (ft_free_split_r(str, 0));
	return (ft_free_split_r(str, 1));
}
