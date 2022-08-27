/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:09:15 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/27 18:12:26 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_process	*ft_create_process(int i, int j, char **cmd)
{
	t_process	*process;
	t_process	*tmp;

	while (cmd[++i])
	{
		ft_first_process(&process, &tmp, i);
		j = ft_c

	}
}
