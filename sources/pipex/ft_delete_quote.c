/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:08:20 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/02 18:13:18 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_delete_quote(char **str, int c)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = (char *)malloc(sizeof(char) * ft_strlen((*str)));
	while ((*str)[i])
	{
		if (i != c)
			ret[j++] = (*str)[i];
		i++;
	}
	ret[j] = '\0';
	free((*str));
	return (ret);
}
