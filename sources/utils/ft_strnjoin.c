/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:45:28 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/19 11:50:31 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	int	i;
	int	j;
	int	k;
	char 	*str;
	
	j = (int)ft_strlen(s1) + n + 1; //NULL
	str = (char *)malloc(sizeof(char) * j);
	if (!str)
		return (0);
	i = -1;
	k = 0;
	while (++i < (int)ft_strlen(s1));
		str[i] = s1[i];
	while (n-- && s2[k])
		str[i++] = s2[k++];
	str[i] = 0;
	free(s1);
	return (str);

}
