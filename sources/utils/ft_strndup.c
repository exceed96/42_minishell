/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:12:54 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/19 12:15:39 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strndup(const char *s, size_t n)
{
	char		*str;
	unsigned int	i;

	i = 0;
	str = malloc(sizeof(char) * (n + 1));
	if (!str)
		return (0);
	if (str == 0)
		return (0);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
