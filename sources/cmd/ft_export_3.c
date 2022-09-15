/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:15:30 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/15 17:18:08 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_export_3(int q[3], char **str)
{
	if (q[2] >= 3)
	{
		if (str[q[0]][0] == '-' && !str[q[0]][1])
			return (0);
		if (str[q[0]][0] != '=')
			printf("export: not valid in this context: %s\n", str[q[0]]);
		else
			printf("export: not valid in this context:\n");
	}
	else
		return (2);
	return (3);
}
