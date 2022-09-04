/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:36:50 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/04 19:09:45 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_search_quote(char **str, int i, int j)
{
	int		x;
	char	c;

	i = -1;
	c = '\0';
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (c == '\0' && (str[i][j] == '"' || str[i][j] == '\''))
			{
				c = str[i][j];
				x = j;
			}
			else if (c == str[i][j])
			{
				c = '\0';
				str[i] = ft_delete_quote(&str[i], x);
				str[i] = ft_delete_quote(&str[i], j - 1);
				j -= 2;
			}
		}
	}
	return (str);
}
