/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:10:12 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 13:11:56 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strsjoin(char *s1, char *s2, int n)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	j = ft_strlen(s2) + n + 1;
	k = 0;
	str = (char *)malloc(sizeof(char) * j);
	if (!str)
		return (0);
	i = -1;
	while (++i < (int)ft_strlen(s1))
		str[i] = s1[i];
	while (n-- && s2[k])
		str[i++] = s2[k++];
	str[i] = '\0';
	free(s2);
	return (str);
}
