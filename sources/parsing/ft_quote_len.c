/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:44:45 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/02 13:03:00 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_quote_len(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '>' && str[i] != '<')
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			c = str[i++];
			while (str[i] && str[i] != c)
				i++;
			if (str[i] && (str[i] != ' ' && str[i] != '>' && str[i] != '<'))
				i++;
		}
		else
			i++;
	}
	return (i);
}
