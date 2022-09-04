/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:03:57 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/31 16:04:51 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_cmd(char *str, char *cmd)
{
	int	i;

	i = 0;
	if (ft_strlen(str) != ft_strlen(cmd))
		return (1);
	while (cmd[i])
	{
		if (str[i] != cmd[i])
			return (1);
		i++;
	}
	return (0);
}
