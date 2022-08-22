/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:09:38 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/22 18:28:56 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_remove_env(char *str, int x, int y)
{
	int		i;
	int		j;
	char	*r_str;

	i = 0;
	j = 0;
	r_str = (char *)malloc(sizeof(char) * (int)ft_strlen(str) - (x - y));
	while (str[i])
	{
		if (i < x || i > y)
			r_str[j++] = str[i];
		i++;
	}
	r_str[j - 1] = 0;
	free(str);
	return (r_str);
}
