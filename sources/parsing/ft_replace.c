/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:54:31 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/25 12:18:51 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_replace(char *cmd, char *str, int i, int j)
{
	char	*r_str;
	int		x;
	int		y;
	int		z;

	x = 0;
	y = 0;
	z = 0;
	r_str = malloc(sizeof(char) * (ft_strlen(cmd) + ft_strlen(str)) + 1);
	if (!r_str)
		return (0);
	while (cmd[z])
	{
		if (x == j)
		{
			while (str[y])
				r_str[x++] = str[y++];
			z += (i - j);
		}
		else
			r_str[x++] = str[z++];
	}
	r_str[x] = '\0';
	free(str);
	return (r_str);
}
