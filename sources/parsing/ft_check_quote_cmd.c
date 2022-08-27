/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_quote_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:54:12 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/27 16:55:44 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_check_quote_cmd(char **cmd, int i, int *j, char *c)
{
	*c = cmd[i][(*y)++];
	while (cmd[i][*j] && cmd[i][(*j)] != *c)
		(*j)++;
}
