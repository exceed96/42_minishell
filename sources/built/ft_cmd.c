/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:01:20 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/02 16:02:13 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cmd(char *str, char *cmd)
{
	int	i;

	i = 0;
	if (ft_strlen(cmd) != ft_strlen(str))
		return (1);
	while (cmd[i])
	{
		if (str[i] != cmd[i])
			return (1);
		i++;
	}
	return (0);
}
