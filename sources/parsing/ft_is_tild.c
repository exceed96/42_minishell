/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_tild.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:47:17 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/25 12:53:34 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_tild(char *cmd, int i)
{
	if (cmd[i] == '~')
	{
		if (cmd[i + 1])
			if (cmd[i + 1] == '~')
				return (0);
		if (cmd[i - 1])
			if (cmd[i - 1] == '~')
				return (0);
	}
	return (1);
}
