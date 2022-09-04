/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_quote_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:27:35 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 13:32:29 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_search_quote_2(char *cmd, int i)
{
	char	c;
	int		x;

	c = '\0';
	i = -1;
	while (cmd[++i])
	{
		if (c == '\0' && (cmd[i] == '\'' || cmd[i] == '"'))
		{
			c = cmd[i];
			x = i;
		}
		else if (c == cmd[i])
		{
			c = '\0';
			cmd = ft_delete_quote(&cmd, x);
			cmd = ft_delete_quote(&cmd, i - 1);
			i -= 2;
		}
	}
	return (cmd);
}
