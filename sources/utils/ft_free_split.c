/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:01:04 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/02 13:01:25 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_split(char **cmd)
{
	int	x;

	x = 0;
	while (cmd[x])
	{
		free(cmd[x]);
		x++;
	}
	free(cmd);
}
