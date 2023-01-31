/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:12:39 by liperman          #+#    #+#             */
/*   Updated: 2022/06/23 15:29:59 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *source, unsigned int start, size_t len)
{
	size_t	i;
	int		j;
	char	*mem;
	int		len_int;

	if (!source)
		return (NULL);
	len_int = (int)len;
	i = 0;
	j = 0;
	if (len > ft_strlen(source))
		mem = (char *) malloc(ft_strlen(source) + 1);
	else
		mem = (char *) malloc(len + 1);
	if (!mem)
		return (NULL);
	while (source[i] != '\0')
	{
		if (i >= start && j < len_int)
			mem[j++] = source[i];
		i++;
	}
	mem[j] = '\0';
	return (mem);
}
