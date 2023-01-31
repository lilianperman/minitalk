/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:37:54 by liperman          #+#    #+#             */
/*   Updated: 2022/06/18 17:21:31 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	count_words(const char *s, char c)
{
	char	*str;
	int		count;

	count = 0;
	str = (char *)s;
	if (c == 0)
		return (1);
	while (*str == c)
		str++;
	while (*str != '\0' && ft_strchr(str, c))
	{
		str = ft_strchr(str, c);
		while (*str == c)
			str++;
		count++;
	}
	if (*str != '\0')
		count ++;
	if (count == 0)
		return (1);
	return (count);
}

char	**malloc_split(const char *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	return (split);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	int		index;

	split = malloc_split(s, c);
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j] = ft_substr(s, index, i - index);
			j++;
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
