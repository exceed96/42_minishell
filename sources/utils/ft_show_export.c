/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:33:16 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/05 17:37:53 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_show_export(char **tmp, int i, int j, int k)
{
	while (tmp[i])
	{
		i = 0;
		k = 0;
		printf("declare -x ");
		while (tmp[i][j])
		{
			if (tmp[i][j] == '=' && tmp[i][j + 1])
			{
				k = 1;
				printf("=\"");
				j++;
			}
			else if (tmp[i][j] == '=')
				j++;
			if (tmp[i][j])
				printf("%c", tmp[i][j]);
			j++;
		}
		if (k)
			printf("\"");
		printf("\n");
		i++;
	}
	ft_free_split(tmp);
}
